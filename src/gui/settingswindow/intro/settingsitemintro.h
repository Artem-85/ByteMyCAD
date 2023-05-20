#ifndef BMC_SETTINGSITEMINTRO_H
#define BMC_SETTINGSITEMINTRO_H

//#include "../settingsitem.h"
#include <QWidget>

class QLabel;
class QVBoxLayout;

class BMC_SettingsItemIntro : public QWidget//BMC_SettingsItem
{
public:
    BMC_SettingsItemIntro(QWidget *parent);
private:
    QLabel *label;
    QVBoxLayout *layout;
};

#endif // BMC_SETTINGSITEMINTRO_H
