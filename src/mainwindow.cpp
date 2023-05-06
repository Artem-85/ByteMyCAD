#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mdi.h"

BMC_MainWindow::BMC_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->Populate();
}

BMC_MainWindow::~BMC_MainWindow()
{
    delete ui;
}

void BMC_MainWindow::Populate()
{
//    // Horizontal layout with 3 buttons
//    QHBoxLayout *hLayout = new QHBoxLayout;
    BMC_MDI *mdiArea = new BMC_MDI;
    this->setCentralWidget(mdiArea);
}

