QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TEMPLATE = app
TARGET = HospitalManagementQt

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    patientwindow.cpp \
    core/Patient.cpp \
    doctorwindow.cpp \
    core/Doctor.cpp

HEADERS += \
    mainwindow.h \
    patientwindow.h \
    core/Patient.h \
    doctorwindow.h \
    core/Doctor.h

FORMS += \
    mainwindow.ui \
    patientwindow.ui \
    doctorwindow.ui
