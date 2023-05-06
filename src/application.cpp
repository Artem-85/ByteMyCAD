#include "application.h"
#include "bytemycad.h"

#include <QDebug>

BMC_Application::BMC_Application(int &argc, char **argv, int flags)
    : QApplication(argc, argv, flags)
{

}

BMC_Application::~BMC_Application()
{
}

void BMC_Application::init()
{
#if defined(DBG)
    qDebug() << "Init App\n";
#endif
    /* Add information about app and developers */
    this->setApplicationDisplayName(BMC_DISPLAY_APP_NAME);
    this->setApplicationName(BMC_APP_NAME);
    this->setApplicationVersion(BMC_VERSION_FULL);
    this->setOrganizationName(BMC_ORGANIZATION_NAME);
    this->setOrganizationDomain(BMC_WEB_ADDRESS);

    /* Prepare signals and slots */
    createActions();

    /* Create app settings. This will automatically include the aforementioned app data */
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
}

void BMC_Application::createActions()
{
    connect(this, &BMC_Application::aboutToQuit, this, &BMC_Application::cleanUp);
}


