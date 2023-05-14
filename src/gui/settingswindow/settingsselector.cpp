#include "settingsselector.h"
#include "intro/settingsitemintro.h"
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

    /* Add the default view directly, without adding it to the tree items list */
    viewsStack->addWidget(introView);
}
