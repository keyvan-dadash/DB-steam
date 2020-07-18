TEMPLATE = subdirs

SUBDIRS += \
    DataBase \
    Steam \
    ViewsAndPresenters

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/ViewsAndPresenters/Game/ -lGame
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/ViewsAndPresenters/Game/ -lGame
else:unix: LIBS += -L$$OUT_PWD/ViewsAndPresenters/Game/ -lGame

INCLUDEPATH += $$PWD/ViewsAndPresenters/Game
DEPENDPATH += $$PWD/ViewsAndPresenters/Game
