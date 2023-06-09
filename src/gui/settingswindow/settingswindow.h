#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>

//class QSplitter;
//class QTreeWidget;
class QDialogButtonBox;
class QAbstractButton;
class BMC_SettingsSelector;

class BMC_SettingsWindow : public QDialog
{
    Q_OBJECT
public:
    BMC_SettingsWindow(QWidget *parent);

    void init();

private:

    void createActions();

//    void populateTree();

    void applyChanges();

    QDialogButtonBox *buttonBox;
    BMC_SettingsSelector *settingsSelector;
//    QSplitter *splitView;
//    QTreeWidget *settingsTree;
//    QWidget *settingWidget;

private slots:

    void onButtonPress(QAbstractButton *button);
};

#endif // SETTINGSWINDOW_H
