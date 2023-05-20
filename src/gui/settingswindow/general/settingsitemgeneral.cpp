#include "settingsitemgeneral.h"

#include <QLabel>
#include <QVBoxLayout>

BMC_SettingsItemGeneral::BMC_SettingsItemGeneral(QWidget *parent)
    : BMC_SettingsItem("General")
{
    label = new QLabel(view);
    layout = new QVBoxLayout(view);
    label->setText(QObject::tr("General settings"));
    label->setAlignment(Qt::AlignCenter);

    layout->addWidget(label);
    view->setLayout(layout);
}
