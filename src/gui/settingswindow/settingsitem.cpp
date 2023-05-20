#include "settingsitem.h"

#include <QWidget>
#include <QList>

BMC_SettingsItem::BMC_SettingsItem(const char *header, BMC_SettingsItem *parent)
    : QTreeWidgetItem(parent),
    childrenItems(new QList<BMC_SettingsItem *>),
    view(new QWidget)
{
    this->setText(0, QAction::tr(header));
}

//BMC_SettingItem::BMC_SettingItem(const char *header, BMC_SettingsTree *parent)
//    : QTreeWidgetItem(parent), views(new QList<BMC_SettingItem>), view(new QWidget)
//{
//    this->setText(0, QAction::tr(header/*VIEW_NAME*/));
//}

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

//int BMC_SettingItem::getId()
//{
//    if (this->data(0, Qt::UserRole).isValid()) {
//        return this->data(0, Qt::UserRole).toInt();
//    }
//    return -1;
//}
