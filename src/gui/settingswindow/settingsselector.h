#ifndef BMC_SETTINGSSELECTOR_H
#define BMC_SETTINGSSELECTOR_H

#include <QSplitter>

class QTreeWidget;
template <>
class QList<QWidget>;

class BMC_SettingsSelector : public QSplitter
{
    Q_OBJECT
public:
    BMC_SettingsSelector(QWidget *parent);
private:
    void init();
    QTreeWidget *settingsTree;
    QWidget *currentSettingView;
};

#endif // BMC_SETTINGSSELECTOR_H
