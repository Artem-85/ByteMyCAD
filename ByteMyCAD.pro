QT       += core gui widgets

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/application.cpp \
    src/bytemycad.cpp \
    src/mainmenubar.cpp \
    src/mainwindow.cpp \
    src/mdi.cpp \
    src/menu.cpp \
    src/settingswindow.cpp

HEADERS += \
    src/application.h \
    src/bytemycad.h \
    src/mainmenubar.h \
    src/mainwindow.h \
    src/mdi.h \
    src/menu.h \
    src/settingswindow.h \
    src/version.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    translations/ByteMyCAD_sv_FI.ts
CONFIG += lrelease
CONFIG += embed_translations

CONFIG(debug, debug|release) {
    DEFINES += DBG
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    build/debug/.qm/ByteMyCAD_sv_FI.qm \
    translations/ByteMyCAD_sv_FI.ts
