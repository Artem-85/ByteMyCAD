#ifndef BMC_SETTINGSSELECTOR_H
#define BMC_SETTINGSSELECTOR_H

#include <QSplitter>

class QTreeWidget;
class BMC_SettingsItem;
template <>
class QList<BMC_SettingsItem>;
class QStackedLayout;
class BMC_SettingsItemIntro;

class BMC_SettingsSelector : public QSplitter
{
    Q_OBJECT
public:
    BMC_SettingsSelector(QWidget *parent);
    void addSettingItem(BMC_SettingsItem *item);

    static void addSettingViewsToStack(QStackedLayout *stack, BMC_SettingsItem *item);
private:
    void init();
    QTreeWidget *settingsTree;
    QWidget *currentSettingView;
    QStackedLayout *viewsStack;
    BMC_SettingsItemIntro *introView;
    QList<BMC_SettingsItem *> *treeItems;
};

#endif // BMC_SETTINGSSELECTOR_H
