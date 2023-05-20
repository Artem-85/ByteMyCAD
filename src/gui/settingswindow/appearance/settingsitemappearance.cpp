#include "settingsitemappearance.h"

#include <QLabel>
#include <QVBoxLayout>

BMC_SettingsItemAppearance::BMC_SettingsItemAppearance(QWidget *parent)
    : BMC_SettingsItem("Appearance")
{
    label = new QLabel(view);
    layout = new QVBoxLayout(view);
    label->setText(QObject::tr("Appearance settings"));
    label->setAlignment(Qt::AlignCenter);

    layout->addWidget(label);
    view->setLayout(layout);
}
