#include "settingsitemlocalization.h"

#include <QLabel>
#include <QVBoxLayout>

BMC_SettingsItemLocalization::BMC_SettingsItemLocalization(BMC_SettingsItem *parent)
    : BMC_SettingsItem("Localization", parent)
{
    label = new QLabel(view);
    layout = new QVBoxLayout(view);
    label->setText(QObject::tr("Localization"));
    label->setAlignment(Qt::AlignCenter);

    layout->addWidget(label);
    view->setLayout(layout);
}
