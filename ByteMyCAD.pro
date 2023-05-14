QT       += core gui widgets

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/application.cpp \
    src/bytemycad.cpp \
    src/gui/mainwindow/mainmenubar.cpp \
    src/gui/mainwindow/mainwindow.cpp \
    src/gui/mainwindow/mdi.cpp \
    src/gui/mainwindow/menu.cpp \
    src/gui/settingswindow/intro/settingsitemintro.cpp \
    src/gui/settingswindow/settingsitem.cpp \
    src/gui/settingswindow/settingsselector.cpp \
    src/gui/settingswindow/settingswindow.cpp

HEADERS += \
    src/application.h \
    src/bytemycad.h \
    src/gui/mainwindow/mainmenubar.h \
    src/gui/mainwindow/mainwindow.h \
    src/gui/mainwindow/mdi.h \
    src/gui/mainwindow/menu.h \
    src/gui/settingswindow/intro/settingsitemintro.h \
    src/gui/settingswindow/settingsitem.h \
    src/gui/settingswindow/settingsselector.h \
    src/gui/settingswindow/settingswindow.h \
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
