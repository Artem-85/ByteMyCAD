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
#include "mainwindow.h"

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

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = BMC_APP_NAME "_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }
    BMC_MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
