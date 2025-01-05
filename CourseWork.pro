QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Board.cpp \
    Game.cpp \
    GameWindow.cpp \
    Logic.cpp \
    MatrixSizeSelectionWindow.cpp \
    Menu.cpp \
    NameInputWindow.cpp \
    RecordsWindow.cpp \
    ScorePanel.cpp \
    Visualization.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Board.h \
    Game.h \
    GameWindow.h \
    Logic.h \
    MatrixSizeSelectionWindow.h \
    Menu.h \
    NameInputWindow.h \
    RecordsWindow.h \
    ScorePanel.h \
    Visualization.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
