#include "settingswindow.h"

BMC_SettingsWindow::BMC_SettingsWindow(QWidget *parent)
    : QDialog(parent)
{
    init();
}

void BMC_SettingsWindow::init()
{

    /* Set parameters of the window */
    setModal(true);
    setAttribute(Qt::WA_DeleteOnClose);

    setFixedSize(800,600);
    setWindowTitle(tr("Application Preferences"));

//    // setup the properties tree
//    splitView()->addWidget(propsTree());
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

//    // add elements to the main layout
//    mainLayout()->addWidget(splitView());
//    mainLayout()->addWidget(buttonBox());
//    setLayout(mainLayout());

//    connect(propsTree(), &QTreeWidget::itemClicked, this, &QTC_PreferenceWindow::onTreeItemClick);
//    connect(buttonBox(), &QDialogButtonBox::accepted, this, &QTC_PreferenceWindow::accept);
//    connect(buttonBox(), &QDialogButtonBox::clicked, this, &QTC_PreferenceWindow::apply);
//    connect(buttonBox(), &QDialogButtonBox::rejected, this, &QTC_PreferenceWindow::reject);

}
