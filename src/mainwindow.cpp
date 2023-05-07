#include "bytemycad.h"
#include "mainwindow.h"
#include "mainmenubar.h"
#include "menu.h"
#include "mdi.h"
#include "settingswindow.h"
#include "ui_mainwindow.h"


#include <QSettings>
#include <QMessageBox>
#include <QAction>
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
#if defined(DBG)
    qDebug() << "SETTINGS/MainWindow";
#endif
    settings->beginGroup("MainWindow");
    const auto geometry = settings->value("geometry", QByteArray()).toByteArray();
    if (geometry.isEmpty()) {
        setGeometry(200, 200, 400, 400);
#if defined(DBG)
        qDebug() << "\tno stored window geometry found";
#endif
    } else {
        restoreGeometry(geometry);
#if defined(DBG)
        qDebug() << "\twindow geometry restored";
#endif
    }
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

    /* Quit from application */
    actionQuit = new QAction(tr("&Quit"),this);
    actionQuit->setShortcuts(QKeySequence::Quit);
    actionQuit->setStatusTip(tr("Quit from application"));
    connect(actionQuit, &QAction::triggered, this, &BMC_MainWindow::close);

    /* Open application settings */
    actionSettings = new QAction(tr("Settings"),this);
    actionSettings->setShortcuts(QKeySequence::Preferences);
    actionSettings->setStatusTip(tr("Edit application's settings"));
    connect(actionSettings, &QAction::triggered, this, &BMC_MainWindow::openSettingsWindow);
}

void BMC_MainWindow::createMainMenu()
{
    mainMenuBar = new BMC_MainMenuBar(this);
    this->setMenuBar(mainMenuBar);

    /* File:
     * |---------
     * |-Quit
     */
    BMC_Menu *menuFile = mainMenuBar->addMenu(tr("&File"));
    menuFile->addSeparator();
    menuFile->addAction(actionQuit);

    /* Edit:
     * |---------
     * |-Settings
     */
    BMC_Menu *menuEdit = mainMenuBar->addMenu(tr("&Edit"));
    menuEdit->addSeparator();
    menuEdit->addAction(actionSettings);

}

void BMC_MainWindow::init()
{
    /* Setup the window parameters */
    this->setWindowTitle(BMC_DISPLAY_APP_NAME);
    /* Setup the MDI */
    mdiArea = new BMC_MDI(this);
    this->setCentralWidget(mdiArea);
    /* Setup actions */
    createActions();
    /* Setup main menu bar */
    createMainMenu();
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

void BMC_MainWindow::openSettingsWindow()
{
    BMC_SettingsWindow *settingsWindow = new BMC_SettingsWindow(this);
//    settingsWindow->initPrefWindow();
    settingsWindow->exec();
}
