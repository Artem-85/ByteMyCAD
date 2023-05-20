#include "settingsitemappearance.h"

#include <QLabel>
#include <QVBoxLayout>

BMC_SettingsItemAppearance::BMC_SettingsItemAppearance(QTreeWidget *parent)
    : BMC_SettingsItem(parent)
{
    this->setText(0, QAction::tr("Appearance"));
    label = new QLabel(view);
    layout = new QVBoxLayout(view);
    label->setText(QObject::tr("Appearance settings"));
    label->setAlignment(Qt::AlignCenter);

    layout->addWidget(label);
    view->setLayout(layout);
}
