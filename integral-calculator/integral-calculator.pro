QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

SOURCES += \
    expression.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    result.cpp \
    tree.cpp

HEADERS += \
    expression.h \
    mainwindow.h \
    qcustomplot.h \
    result.h \
    tree.h

FORMS += \
    mainwindow.ui \
    result.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
