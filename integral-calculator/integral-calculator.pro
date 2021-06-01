QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

SOURCES += \
    enterfile.cpp \
    evaluation.cpp \
    expression.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    result.cpp \
    savefile.cpp \
    tree.cpp

HEADERS += \
    enterfile.h \
    evaluation.h \
    expression.h \
    mainwindow.h \
    qcustomplot.h \
    result.h \
    savefile.h \
    tree.h

FORMS += \
    enterfile.ui \
    mainwindow.ui \
    result.ui \
    savefile.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
