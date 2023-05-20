#ifndef BMC_SETTINGSITEMGENERAL_H
#define BMC_SETTINGSITEMGENERAL_H

#include "../settingsitem.h"

class QLabel;
class QVBoxLayout;

class BMC_SettingsItemGeneral : public BMC_SettingsItem
{
public:
    BMC_SettingsItemGeneral(QWidget *parent);
private:
    QLabel *label;
    QVBoxLayout *layout;
};

#endif // BMC_SETTINGSITEMGENERAL_H
