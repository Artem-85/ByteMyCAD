#ifndef BMC_SETTINGSITEM_H
#define BMC_SETTINGSITEM_H

#include <QTreeWidgetItem>

class BMC_SettingsItem : public QTreeWidgetItem
{
public:
    BMC_SettingsItem(const char *header);
    ~BMC_SettingsItem();
protected:
//    /**
//     * @brief Children views.
//     */
//    QList<BMC_SettingItem> *views;

//    /**
//     * @brief Header of the view to be represented in the tree.
//     */
//    QString header;

    /**
     * @brief The content of the view.
     */
    QWidget *view;
};

#endif // BMC_SETTINGSITEM_H
