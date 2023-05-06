/**
 * @file bytemycad.cpp
 * @brief Source code for application's entry point
 *
 * @author Artem Plyusnin
 *
 *
 */
#include "bytemycad.h"
#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ByteMyCAD_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }
    BMC_MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
