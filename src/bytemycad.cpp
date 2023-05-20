/**
 * @file bytemycad.cpp
 * @brief Source code for application's entry point
 *
 * @author Artem Plyusnin
 *
 *
 */
#include "bytemycad.h"
#include "application.h"
#include "gui/mainwindow/mainwindow.h"

#include <QLocale>
#include <QTranslator>
#include <QSettings>

/**
 * @brief Entry point to the application
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    /* Create and initiallize the application */
    BMC_Application app(argc, argv);
    app.init();

    /* Create and initialize the main window */
    BMC_MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
