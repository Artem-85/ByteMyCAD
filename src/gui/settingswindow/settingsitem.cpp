#include "settingsitem.h"

#include <QTreeWidget>
#include <QList>

BMC_SettingsItem::BMC_SettingsItem(QTreeWidget *parent)
    : QTreeWidgetItem(parent),
    childrenItems(new QList<BMC_SettingsItem *>),
    view(new QWidget),
    id(-1)
{
}

BMC_SettingsItem::BMC_SettingsItem(BMC_SettingsItem *parent)
    : QTreeWidgetItem(parent),
    childrenItems(new QList<BMC_SettingsItem *>),
    view(new QWidget),
    id(-1)
{
}

BMC_SettingsItem::~BMC_SettingsItem()
{
//    delete views;
//    delete view;
}

void BMC_SettingsItem::addSettingItem(BMC_SettingsItem *item)
{
    /* Add top-level items to the list */
    childrenItems->append(item);
}

bool BMC_SettingsItem::isLeafItem()
{
    return childrenItems->isEmpty();
}
