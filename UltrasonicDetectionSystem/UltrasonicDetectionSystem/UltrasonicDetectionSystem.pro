#-------------------------------------------------
#
# Project created by QtCreator 2019-06-14T21:41:46
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = UltrasonicDetectionSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        UltrasonicDetectionSystem.cpp \
    Login.cpp \
    TimeDomain.cpp \
    FrequencyDomain.cpp \
    Database.cpp \
    qcustomplot.cpp

HEADERS += \
        UltrasonicDetectionSystem.h \
    Login.h \
    TimeDomain.h \
    FrequencyDomain.h \
    Database.h \
    qcustomplot.h

FORMS += \
        UltrasonicDetectionSystem.ui \
    Login.ui \
    TimeDomain.ui \
    FrequencyDomain.ui \
    Database.ui

LIBS += $$PWD/fftw-3.3.5-dll32/libfftw3-3.lib
LIBS += $$PWD/fftw-3.3.5-dll32/libfftw3f-3.lib
LIBS += $$PWD/fftw-3.3.5-dll32/libfftw3l-3.lib


RC_ICONS = UDP.ico

RESOURCES += \
    image.qrc

DISTFILES +=
