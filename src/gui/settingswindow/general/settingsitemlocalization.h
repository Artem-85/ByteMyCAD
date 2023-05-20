#ifndef BMC_SETTINGSITEMLOCALIZATION_H
#define BMC_SETTINGSITEMLOCALIZATION_H

#include "../settingsitem.h"

class QLabel;
class QVBoxLayout;

class BMC_SettingsItemLocalization : public BMC_SettingsItem
{
public:
    BMC_SettingsItemLocalization(BMC_SettingsItem *parent = nullptr);
private:
    QLabel *label;
    QVBoxLayout *layout;
};

#endif // BMC_SETTINGSITEMLOCALIZATION_H
