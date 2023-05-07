#include "settingswindow.h"

#include <QSplitter>
#include <QTreeWidget>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QAbstractButton>
#include <QLabel>

BMC_SettingsWindow::BMC_SettingsWindow(QWidget *parent)
    : QDialog(parent)
{
    init();
}

void BMC_SettingsWindow::createActions()
{
//    connect(settingsTree, &QTreeWidget::itemClicked, this, &BMC_SettingsWindow::onTreeItemClick);
    /* This works for all three buttons */
    connect(buttonBox, &QDialogButtonBox::clicked, this, &BMC_SettingsWindow::onButtonPress);
}

void BMC_SettingsWindow::init()
{

    /* Set parameters of the window */
    this->setModal(true);
    this->setAttribute(Qt::WA_DeleteOnClose);

    this->setFixedSize(800, 600);
    this->setWindowTitle(tr("Application Preferences"));

    QVBoxLayout *mainLayout = new QVBoxLayout;

    buttonBox = new QDialogButtonBox((QDialogButtonBox::Ok | QDialogButtonBox::Apply | QDialogButtonBox::Cancel), this);

    splitView = new QSplitter(this);
    settingsTree = new QTreeWidget(splitView);
    settingWidget = new QWidget(splitView);

    splitView->addWidget(settingsTree);
    splitView->addWidget(settingWidget);
    splitView->setCollapsible(0, false);
    splitView->setCollapsible(1, false);

    settingsTree->setMinimumWidth(150);
    settingsTree->setMaximumWidth(400);
    settingsTree->sizeHint();

    QLabel *introLabel = new QLabel(settingWidget);
    introLabel->setText(tr("Select setting to edit"));
    introLabel->setAlignment(Qt::AlignCenter);
    QVBoxLayout *settingWidgetLayout = new QVBoxLayout(settingWidget);
    settingWidgetLayout->addWidget(introLabel);
    settingWidget->setLayout(settingWidgetLayout);

    /* Populate main layout */
    mainLayout->addWidget(splitView);
    mainLayout->addWidget(buttonBox);

    /* Set layout to the window */
    this->setLayout(mainLayout);

    this->createActions();

//    // setup the properties tree

//    splitView()->setCollapsible(0,false);
//    splitView()->setCollapsible(1,false);
//    //    splitView()->setSizePolicy(QSizePolicy::Minimum);
//    //    splitView()->setMinimumWidth(300);
//    propsTree()->setColumnCount(1);
//    propsTree()->setHeaderHidden(true);
//    populatePropsTree();
//    propsTree()->setMinimumWidth(150);
//    propsTree()->setColumnWidth(0,150);
//    //    propsTree()->sizeHint();

//    QSettings settings;
//    settings.beginGroup("PropertiesTree");
//    settings.endGroup();

}

void BMC_SettingsWindow::applyChanges()
{
#if defined(DBG)
    qDebug() << "Process changes\n";
#endif
}

void BMC_SettingsWindow::onButtonPress(QAbstractButton *button)
{
    switch (buttonBox->buttonRole(button))
    {
    case QDialogButtonBox::ApplyRole:
        applyChanges();
        break;
    case QDialogButtonBox::AcceptRole:
        applyChanges();
        this->close();
        break;
    default:
        this->close();
        break;
    }
}
