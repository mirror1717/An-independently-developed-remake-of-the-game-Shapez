QT       += core gui \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QT += core gui multimedia


SOURCES += \
    belt.cpp \
    choose.cpp \
    control.cpp \
    cutter.cpp \
    gameinterface.cpp \
    main.cpp \
    mine.cpp \
    miner.cpp \
    shop.cpp \
    start.cpp \
    stone.cpp \
    tools.cpp \
    trash.cpp \
    win.cpp

HEADERS += \
    belt.h \
    choose.h \
    control.h \
    cutter.h \
    gameinterface.h \
    mine.h \
    miner.h \
    shop.h \
    start.h \
    stastic.h \
    stone.h \
    tools.h \
    trash.h \
    win.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
QMAKE_CXXFLAGS += -fstack-protector-strong
QMAKE_LFLAGS += -fstack-protector-strong

RESOURCES += \
    picture.qrc
