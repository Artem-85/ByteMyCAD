#include "application.h"
#include "bytemycad.h"

BMC_Application::BMC_Application(int &argc, char **argv, int flags)
    : QApplication(argc, argv, flags)
{

}

BMC_Application::~BMC_Application()
{
    delete settings;
}

void BMC_Application::init()
{
    /* Add information about app and developers */
    this->setApplicationDisplayName(BMC_DISPLAY_APP_NAME);
    this->setApplicationName(BMC_APP_NAME);
    this->setApplicationVersion(BMC_VERSION_FULL);
    this->setOrganizationName(BMC_ORGANIZATION_NAME);
    this->setOrganizationDomain(BMC_WEB_ADDRESS);

    /* Create app settings. This will automatically include the aforementioned app data */
    settings = new QSettings;
}

//connect(this, &QTC_Application::aboutToQuit, this, &QTC_Application::cleanUp);
