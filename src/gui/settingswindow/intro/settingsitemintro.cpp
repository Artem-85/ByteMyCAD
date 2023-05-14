#include "settingsitemintro.h"

#include <QLabel>
#include <QVBoxLayout>

BMC_SettingsItemIntro::BMC_SettingsItemIntro(QWidget *parent)
//    : BMC_SettingsItem("Intro"),
    : QWidget(parent),
    label(new QLabel),
    layout(new QVBoxLayout)
{
    label->setText(QObject::tr("Select setting in the tree to edit"));
    label->setAlignment(Qt::AlignCenter);

    layout->addWidget(label);
    this->setLayout(layout);
}


//BMC_SettingViewIntro::BMC_SettingViewIntro(BMC_SettingsTree *parent)
//    : BMC_SettingItem("Intro", parent)
//{
//    label = new QLabel;
//    label->setText(QObject::tr("Select setting in the tree to edit"));
//    label->setAlignment(Qt::AlignCenter);
//    layout = new QVBoxLayout;
//    layout->addWidget(label);
//    view->setLayout(layout);
//}

//BMC_SettingViewIntro::BMC_SettingViewIntro()
//    : BMC_SettingViewIntro(nullptr)
//{
//}

//BMC_SettingViewIntro::~BMC_SettingViewIntro()
//{
//    delete label;
//    delete layout;
//}
