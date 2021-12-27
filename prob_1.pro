QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    categorieswin.cpp \
    main.cpp \
    mainwindow.cpp \
    qdynamicbox.cpp \
    qdynamicboxtouploaded.cpp \
    qdynamicbutton.cpp \
    qdynamiccheckbox.cpp \
    qdynamiccheckboxtofile.cpp \
    qdynamiccheckboxtopost.cpp \
    registrationwin.cpp \
    scaledpixmap.cpp \
    secondwindow.cpp \
    userprofilewin.cpp

HEADERS += \
    categorieswin.h \
    mainwindow.h \
    qdynamicbox.h \
    qdynamicboxtouploaded.h \
    qdynamicbutton.h \
    qdynamiccheckbox.h \
    qdynamiccheckboxtofile.h \
    qdynamiccheckboxtopost.h \
    registrationwin.h \
    scaledpixmap.h \
    secondwindow.h \
    userprofilewin.h

FORMS += \
    categorieswin.ui \
    mainwindow.ui \
    registrationwin.ui \
    secondwindow.ui \
    userprofilewin.ui

win32:RC_FILE = file.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
