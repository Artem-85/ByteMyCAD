#include "application.h"
#include "bytemycad.h"

#if defined(DBG)
#   include <QDebug>
#endif
#include <QTranslator>

BMC_Application::BMC_Application(int &argc, char **argv, int flags)
    : QApplication(argc, argv, flags)
{
}

BMC_Application::~BMC_Application()
{
}

void BMC_Application::readSettings()
{
    /* Set localization data */
#if defined(DBG)
    qDebug() << "SETTINGS/Localization";
#endif
    settings->beginGroup("Localization");
    if (!settings->value("locale").isValid()) {
#if defined(DBG)
        qDebug() << "\tno stored locale found";
#endif
        setAppLocale();
    } else {
        locale = new QLocale(settings->value("locale", QLocale()).toLocale());
#if defined(DBG)
        qDebug() << "\tlocale restored";
#endif
    }
    settings->endGroup();
}

void BMC_Application::writeSettings()
{
    QSettings * const settings = bmcApp->getSettings();

    /* Save window size and position */
    settings->beginGroup("Localization");
    settings->setValue("locale", *locale);
    settings->endGroup();
}

void BMC_Application::setAppLocale()
{
    translator = new QTranslator;

    /* TODO check settings and load locale from settings */

    /* If no settings found: look for translation matching the system language */
    const QStringList uiLanguages = QLocale::system().uiLanguages();
#if defined(DBG)
    qDebug() << "Available system UI languages:\n";
#endif
    for (const QString &systemLocaleName : uiLanguages) {
#if defined(DBG)
        qDebug() << systemLocaleName << Qt::endl;
#endif
        const QString baseName = BMC_APP_NAME "_" + QLocale(systemLocaleName).name();
        if (translator->load(":/i18n/" + baseName)) {
            /* Setup app locale */
            locale = new QLocale(systemLocaleName);
            /* Apply translation */
            this->installTranslator(translator);
#if defined(DBG)
            qDebug() << "Applied translation: " << baseName << Qt::endl;
#endif
            break;
        }
    }

//    /* If no translation matching system language has been found */
//    if (translator->isEmpty()) {
//        if (!translator->load(":/i18n/" BMC_APP_NAME "_en_US")) {
//            ; // TODO exit from app with error
//#if defined(DBG)
//            qDebug() << "CRITICAL: No translation data has been found";
//#endif
//        }
//    }
}

void BMC_Application::init()
{
#if defined(DBG)
    qDebug() << "Init App";
    qDebug() << "Version: " BMC_VERSION_FULL;
#endif
    /* Add information about app and developers */
    this->setApplicationDisplayName(BMC_DISPLAY_APP_NAME);
    this->setApplicationName(BMC_APP_NAME);
    this->setApplicationVersion(BMC_VERSION_FULL);
    this->setOrganizationName(BMC_ORGANIZATION_NAME);
    this->setOrganizationDomain(BMC_WEB_ADDRESS);

    /* Prepare signals and slots */
    createActions();

    /* Create app settings. This will use aforementioned info
     * to correctly name and place the settings in the OS registry or configuration files */
    settings = new QSettings;
    readSettings();
}

void BMC_Application::cleanUp()
{
#if defined(DBG)
    qDebug() << "Cleanup app\n";
#endif
    writeSettings();
    delete settings;
    delete translator;
    delete locale;
}

void BMC_Application::createActions()
{
    connect(this, &BMC_Application::aboutToQuit, this, &BMC_Application::cleanUp);
}


