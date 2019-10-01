TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../../

SOURCES += \
        sort_students.cpp

HEADERS += \
    student.h \
    ../../profile.h \
    ../../test_runner.h
