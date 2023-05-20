/**
 *  @file bytemycad.h
 *  @brief Contains application-wide definitions, mostly string literal constants
 *
 *  @author Artem Plyusnin
 */

#ifndef BITEMYCAD_H
#define BITEMYCAD_H

#include "version.h"
#include "application.h"

/**
 * @brief Stringify argument
 */
#define BMC_STR(_x) #_x
#define BMC_STRINGIFY(_x) BMC_STR(_x)

//#define BMC_MAJOR_VERSION 0
//#define BMC_MINOR_VERSION 0
//#define BMC_REVISION 2
//#define BMC_BUILD "none"
//#define BMC_VERSION_TIME __TIME__

#define BMC_APP_NAME "ByteMyCAD"
#define BMC_APP_DESCRIPTION ": absolutely incapable CAD which won't solve your problems"
#define BMC_DISPLAY_APP_NAME "ByteMyCAD"
#define BMC_ORGANIZATION_NAME "ByteMyCad Inc"
#define BMC_CONTACT_EMAIL "bytemycad@proton.me"
#define BMC_WEB_ADDRESS "bytemycad.io"
#define BMC_VERSION_FULL BMC_STRINGIFY(BMC_MAJOR_VERSION) "." BMC_STRINGIFY(BMC_MINOR_VERSION) "." BMC_STRINGIFY(BMC_REVISION) "-" BMC_BUILD " " BMC_VERSION_TIME

/**
 * @def bmcApp
 * @brief Get the instance of the application.
 * @return Pointer to the object of @ref BMC_Application
 *
 */
#if defined(bmcApp)
#undef bmcApp
#endif
#define bmcApp (static_cast<BMC_Application *>(QCoreApplication::instance()))

#endif // BITEMYCAD_H
