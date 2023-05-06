#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mdi.h"

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

void BMC_MainWindow::init()
{
    mdiArea = new BMC_MDI(this);
    this->setCentralWidget(mdiArea);
}

