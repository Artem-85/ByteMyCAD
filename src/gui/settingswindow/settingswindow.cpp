#include "settingswindow.h"
#include "settingsselector.h"

#include <QSplitter>
#include <QTreeWidget>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QAbstractButton>
#include <QLabel>

BMC_SettingsWindow::BMC_SettingsWindow(QWidget *parent)
    : QDialog(parent, (Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint | Qt::WindowContextHelpButtonHint)),
    settingsSelector(new BMC_SettingsSelector(this))
{
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
    this->setWindowTitle(tr("Application settings"));

    QVBoxLayout *mainLayout = new QVBoxLayout;

    buttonBox = new QDialogButtonBox((QDialogButtonBox::Ok | QDialogButtonBox::Apply | QDialogButtonBox::Cancel), this);

//    splitView = new QSplitter(this);
//    settingsTree = new QTreeWidget(splitView);
//    settingWidget = new QWidget(splitView);

//    splitView->addWidget(settingsTree);
//    splitView->addWidget(settingWidget);
//    splitView->setCollapsible(0, false);
//    splitView->setCollapsible(1, false);

//    settingsTree->setMinimumWidth(150);
//    settingsTree->setMaximumWidth(400);
//    settingsTree->sizeHint();

//    QLabel *introLabel = new QLabel(settingWidget);
//    introLabel->setText(tr("Select setting to edit"));
//    introLabel->setAlignment(Qt::AlignCenter);
//    QVBoxLayout *settingWidgetLayout = new QVBoxLayout(settingWidget);
//    settingWidgetLayout->addWidget(introLabel);
//    settingWidget->setLayout(settingWidgetLayout);

    /* Populate main layout */
    mainLayout->addWidget(settingsSelector);
    mainLayout->addWidget(buttonBox);

    /* Set layout to the window */
    this->setLayout(mainLayout);

    this->createActions();

//    this->populateTree();

////    // setup the properties tree

////    splitView()->setCollapsible(0,false);
////    splitView()->setCollapsible(1,false);
////    //    splitView()->setSizePolicy(QSizePolicy::Minimum);
////    //    splitView()->setMinimumWidth(300);
////    propsTree()->setColumnCount(1);
////    propsTree()->setHeaderHidden(true);
////    populatePropsTree();


////    QSettings settings;
////    settings.beginGroup("PropertiesTree");
////    settings.endGroup();

}

//void BMC_SettingsWindow::populateTree()
//{
//    QTreeWidgetItem *settingsGeneral = new QTreeWidgetItem(settingsTree);
//    settingsGeneral->setText(0, tr("General"));
////    propsGeneral->setData(0,Qt::UserRole,propsView()->addWidget(getStartView()));

//    QTreeWidgetItem *settingsGeneralLocalization = new QTreeWidgetItem(settingsGeneral);
//    settingsGeneralLocalization->setText(0, tr("Localization"));
////    propsGeneralInterface->setData(0,Qt::UserRole,propsView()->addWidget(getGeneralInterfaceView()));

//    QTreeWidgetItem *settingsGeneralSystem = new QTreeWidgetItem(settingsGeneral);
//    settingsGeneralSystem->setText(0, tr("System"));

////    QWidget *thirdPageWidget = new QWidget(splitView());
////    QLabel *viewLabel3 = new QLabel(tr("Page 3"),thirdPageWidget);
////    QGridLayout *viewLayout3 = new QGridLayout(thirdPageWidget);
////    viewLayout3->addWidget(viewLabel3);
////    thirdPageWidget->setLayout(viewLayout3);

////    propsGeneralSystem->setText(0,tr("System"));
////    propsGeneralSystem->setData(0,Qt::UserRole,propsView()->addWidget(thirdPageWidget));

//    settingsTree->addTopLevelItem(settingsGeneral);

//}

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
