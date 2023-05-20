#include "settingsselector.h"
#include "intro/settingsitemintro.h"
#include "general/settingsitemgeneral.h"
#include "appearance/settingsitemappearance.h"
#include <QTreeWidget>
#include <QStackedLayout>

BMC_SettingsSelector::BMC_SettingsSelector(QWidget *parent)
    : QSplitter(parent),
    settingsTree(new QTreeWidget(this)),
    currentSettingView(new QWidget(this)),
    viewsStack(new QStackedLayout(this)),
    introView(new BMC_SettingsItemIntro(this)),
    treeItems(new QList<BMC_SettingsItem *>())
{
    init();
}

void BMC_SettingsSelector::init()
{
    this->addWidget(settingsTree);
    this->addWidget(currentSettingView);
    this->setCollapsible(0, false);
    this->setCollapsible(1, false);

    settingsTree->setMinimumWidth(150);
    settingsTree->setMaximumWidth(400);
    settingsTree->sizeHint();

    currentSettingView->setLayout(viewsStack);

    BMC_SettingsItemGeneral *sGeneral = new BMC_SettingsItemGeneral(settingsTree);
    BMC_SettingsItemAppearance *sAppearance = new BMC_SettingsItemAppearance(settingsTree);

    /* Add the default view directly, without adding it to the tree items list */
    int i = viewsStack->addWidget(introView);
    qDebug() << " Intro # in stack: " << i << Qt::endl;

    this->addSettingItem(sGeneral);
    this->addSettingItem(sAppearance);
}

void BMC_SettingsSelector::addSettingItem(BMC_SettingsItem *item)
{
    /* Add top-level items to the list */
    treeItems->append(item);
    settingsTree->addTopLevelItem(item);
    /* This will put the current item's view and all its children recursively into the stack of settings views */
    addSettingViewsToStack(viewsStack, item);
}

void BMC_SettingsSelector::addSettingViewsToStack(QStackedLayout *stack, BMC_SettingsItem *item)
{
    /* Add current view widget to the stack: */
    int i = stack->addWidget(item->getView());
    qDebug() << item->text(0) << " # in stack: " << i << Qt::endl;

    /* If we have any children, go to the next level of recursion */
    if (!item->isLeafItem()) {
        for (BMC_SettingsItem *child: *item->getChildrenItems()) {
            addSettingViewsToStack(stack, child);
        }
    }
}
