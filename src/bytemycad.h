/**
 *  @file bytemycad.h
 *  @brief Contains application-wide definitions, mostly string literal constants
 *
 *  @author Artem Plyusnin
 */

#ifndef BITEMYCAD_H
#define BITEMYCAD_H

#include "version.h"

/**
 * @brief Stringify argument
 */
#define BMC_STR(_x) #_x

#define BMC_APP_NAME "ByteMyCAD: absolutely incapable CAD which won't solve your problems"
#define BMC_DISPLAY_APP_NAME "ByteMyCAD"
#define BMC_ORGANIZATION_NAME "ByteMyCad Inc"
#define BMC_CONTACT_EMAIL "bytemycad@proton.me"
#define BMC_WEB_ADDRESS "bytemycad.io"
#define BMC_VERSION_FULL BMC_STR(BMC_MAJOR_VERSION) "." BMC_STR(BMC_MINOR_VERSION) "." BMC_STR(BMC_REVISION) "-" BMC_BUILD " " BMC_VERSION_TIME


#endif // BITEMYCAD_H
