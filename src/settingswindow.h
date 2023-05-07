#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>

class BMC_SettingsWindow : public QDialog
{
    Q_OBJECT
public:
    BMC_SettingsWindow(QWidget *parent);

private:
    void init();
};

#endif // SETTINGSWINDOW_H
