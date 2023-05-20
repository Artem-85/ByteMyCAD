#ifndef BMC_SETTINGSITEMAPPEARANCE_H
#define BMC_SETTINGSITEMAPPEARANCE_H

#include "../settingsitem.h"

class QLabel;
class QVBoxLayout;

class BMC_SettingsItemAppearance : public BMC_SettingsItem
{
public:
    explicit BMC_SettingsItemAppearance(QTreeWidget *parent);
private:
    QLabel *label;
    QVBoxLayout *layout;
};

#endif // BMC_SETTINGSITEMAPPEARANCE_H
