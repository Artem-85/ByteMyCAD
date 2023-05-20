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
    introView(new BMC_SettingsItemIntro(this))
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

    treeItems = new QList<BMC_SettingsItem *>();

    BMC_SettingsItemGeneral *sGeneral = new BMC_SettingsItemGeneral(settingsTree);
    treeItems->append(sGeneral);

    BMC_SettingsItemAppearance *sAppearance = new BMC_SettingsItemAppearance(settingsTree);
    treeItems->append(sAppearance);

    /* Add the default view directly, without adding it to the tree items list */
    viewsStack->addWidget(introView);
    for (BMC_SettingsItem *item: *treeItems) {
//        qDebug() << "item: " << item->text(0);
        viewsStack->addWidget(item->getView());
        settingsTree->addTopLevelItem(item);
    }
}
