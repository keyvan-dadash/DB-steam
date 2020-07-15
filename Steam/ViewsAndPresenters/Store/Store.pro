QT += gui quickwidgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
DEFINES += STORE_LIBRARY

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    store.cpp

HEADERS += \
    Store_global.h \
    store.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    store.ui

DISTFILES += \
    D:/fucking uni/DB/project/arrowsLeft.png \
    D:/fucking uni/DB/project/arrowsLeft.png \
    D:/fucking uni/DB/project/arrowsRight.png \
    D:/fucking uni/DB/project/colored_body_top2.png

RESOURCES += \
    resourse.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../DataBase/ -lDataBase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../DataBase/ -lDataBase
else:unix: LIBS += -L$$OUT_PWD/../../DataBase/ -lDataBase

INCLUDEPATH += $$PWD/../../DataBase
DEPENDPATH += $$PWD/../../DataBase
