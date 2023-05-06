#include "bytemycad.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mdi.h"

#include <QSettings>
#include <QMessageBox>
#include <QCloseEvent>

BMC_MainWindow::BMC_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->init();
}

BMC_MainWindow::~BMC_MainWindow()
{
    delete mdiArea;
    delete ui;
}

void BMC_MainWindow::readSettings()
{
    QSettings * const settings = bmcApp->getSettings();

    /* Set window size and position */
    settings->beginGroup("MainWindow");
    const auto geometry = settings->value("geometry", QByteArray()).toByteArray();
    if (geometry.isEmpty())
        setGeometry(200, 200, 400, 400);
    else
        restoreGeometry(geometry);
    settings->endGroup();
}

void BMC_MainWindow::writeSettings()
{
    QSettings * const settings = bmcApp->getSettings();

    /* Save window size and position */
    settings->beginGroup("MainWindow");
    settings->setValue("geometry", saveGeometry());
    settings->endGroup();
}

void BMC_MainWindow::createActions()
{
//    connect(this, &BMC_MainWindow::, this, &QTC_MainWindow::updateMenus);
}

void BMC_MainWindow::init()
{
    createActions();
    /* Setup the window parameters */
    this->setWindowTitle(BMC_DISPLAY_APP_NAME);
    /* Setup the MDI */
    mdiArea = new BMC_MDI(this);
    this->setCentralWidget(mdiArea);
    /* Read and apply main window's settings */
    readSettings();
}

void BMC_MainWindow::closeEvent(QCloseEvent* event)
{
    QMessageBox quitConfirmBox;

    quitConfirmBox.setInformativeText(tr("Do you really want to quit?"));
    quitConfirmBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    quitConfirmBox.setDefaultButton(QMessageBox::No);
    quitConfirmBox.setWindowFlags(Qt::FramelessWindowHint);

    const int quitRet = quitConfirmBox.exec();

    switch (quitRet) {
    case QMessageBox::Yes:

        writeSettings();
        event->accept();
        break;

    default:

        event->ignore();
        break;
    }
}
