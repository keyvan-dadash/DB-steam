TEMPLATE = subdirs

SUBDIRS += \
    Friends \
    Game \
    Hub \
    Library \
    Profile \
    Store

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/Store/ -lStore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/Store/ -lStored

INCLUDEPATH += $$PWD/Store
DEPENDPATH += $$PWD/Store

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/Profile/ -lProfile
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/Profile/ -lProfiled
else:unix: LIBS += -L$$OUT_PWD/Profile/ -lProfile

INCLUDEPATH += $$PWD/Profile
DEPENDPATH += $$PWD/Profile

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/Friends/ -lFriends
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/Friends/ -lFriendsd

INCLUDEPATH += $$PWD/Friends
DEPENDPATH += $$PWD/Friends

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/Hub/ -lHub
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/Hub/ -lHubd

INCLUDEPATH += $$PWD/Hub
DEPENDPATH += $$PWD/Hub

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/Library/ -lLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/Library/ -lLibraryd

INCLUDEPATH += $$PWD/Library
DEPENDPATH += $$PWD/Library

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/Game/ -lGame
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/Game/ -lGame
else:unix: LIBS += -L$$OUT_PWD/Game/ -lGame

INCLUDEPATH += $$PWD/Game
DEPENDPATH += $$PWD/Game
