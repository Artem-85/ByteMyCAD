#include "settingsitemintro.h"

#include <QLabel>
#include <QVBoxLayout>

BMC_SettingsItemIntro::BMC_SettingsItemIntro(QWidget *parent)
    : QWidget(parent),
    label(new QLabel),
    layout(new QVBoxLayout)
{
    label->setText(QObject::tr("Select setting in the tree to edit"));
    label->setAlignment(Qt::AlignCenter);

    layout->addWidget(label);
    this->setLayout(layout);
}
