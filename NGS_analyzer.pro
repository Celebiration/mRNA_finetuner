QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    centralizedslider.cpp \
    config.cpp \
    doubleslider.cpp \
    main.cpp \
    mylineedit.cpp \
    ngswindow.cpp \
    optstate.cpp \
    restrictionlistitem.cpp \
    selectcdsdialog.cpp

HEADERS += \
    centralizedslider.h \
    config.h \
    doubleslider.h \
    mylineedit.h \
    ngswindow.h \
    optstate.h \
    restrictionlistitem.h \
    selectcdsdialog.h

FORMS += \
    centralizedslider.ui \
    doubleslider.ui \
    ngswindow.ui \
    restrictionlistitem.ui \
    selectcdsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    config.yaml

RESOURCES += \
    res.qrc

QMAKE_LIBDIR += lib/ViennaRNA-master/src/ViennaRNA
QMAKE_INCDIR += lib/ViennaRNA-master/src/ViennaRNA
