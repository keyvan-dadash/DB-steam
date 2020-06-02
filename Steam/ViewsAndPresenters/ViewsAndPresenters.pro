TEMPLATE = subdirs

SUBDIRS += \
    Store

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/Store/ -lStore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/Store/ -lStored

INCLUDEPATH += $$PWD/Store
DEPENDPATH += $$PWD/Store
