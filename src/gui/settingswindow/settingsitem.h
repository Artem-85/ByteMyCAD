#ifndef BMC_SETTINGSITEM_H
#define BMC_SETTINGSITEM_H

#include <QTreeWidgetItem>

class QTreeWidget;
class BMC_SettingsItem;
template <>
class QList<BMC_SettingsItem>;

class BMC_SettingsItem : public QTreeWidgetItem
{
public:
    explicit BMC_SettingsItem(QTreeWidget *parent);
    explicit BMC_SettingsItem(BMC_SettingsItem *parent);
    ~BMC_SettingsItem();

    QWidget *getView() { return view; }
    QList<BMC_SettingsItem *> *getChildrenItems() { return childrenItems; }
    bool isLeafItem();
    void addSettingItem(BMC_SettingsItem *item);
    void setId(int n) { id = n; }
    int getId() { return id; }
protected:
    /**
     * @brief Children views.
     */
    QList<BMC_SettingsItem *> *childrenItems;

//    /**
//     * @brief Header of the view to be represented in the tree.
//     */
//    QString header;

    /**
     * @brief The content of the view.
     */
    QWidget *view;

    int id;
};

#endif // BMC_SETTINGSITEM_H
