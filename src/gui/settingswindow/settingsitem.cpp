#include "settingsitem.h"

#include <QWidget>

BMC_SettingsItem::BMC_SettingsItem(const char *header)
    : QTreeWidgetItem(),
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

//int BMC_SettingItem::getId()
//{
//    if (this->data(0, Qt::UserRole).isValid()) {
//        return this->data(0, Qt::UserRole).toInt();
//    }
//    return -1;
//}
