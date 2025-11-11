# AI Study Assistant Qt Project File
# This file can be opened in Qt Creator as an alternative to CMake

QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

# Input
INCLUDEPATH += include

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/flashcard.cpp \
    src/flashcardmanager.cpp \
    src/flashcarddialog.cpp

HEADERS += \
    include/mainwindow.h \
    include/flashcard.h \
    include/flashcardmanager.h \
    include/flashcarddialog.h

FORMS += \
    ui/mainwindow.ui \
    ui/flashcarddialog.ui

# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Application name
TARGET = AIStudyAssistant
