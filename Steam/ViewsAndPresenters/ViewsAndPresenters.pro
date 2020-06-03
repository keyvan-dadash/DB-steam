TEMPLATE = subdirs

SUBDIRS += \
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
