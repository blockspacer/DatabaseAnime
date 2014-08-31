QT       += core gui sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DatabaseAnime
TEMPLATE = app

VERSION = 1.0.0.0
RC_ICONS = images/DBA_Icon.ico
QMAKE_TARGET_COMPANY = LibertaSoft
QMAKE_TARGET_PRODUCT = DatabaseAnime
QMAKE_TARGET_DESCRIPTION = Your database of an anime
QMAKE_TARGET_COPYRIGHT = (CopyLeft) LibertaSoft

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    formsettings.cpp \
    imagecover.cpp \
    lookprogressbar.cpp \
    dialogaddanime.cpp \
    dialogaddmanga.cpp \
    dialogaddamv.cpp \
    dialogadddorama.cpp \
    mngrconnection.cpp \
    mngrquerys.cpp \
    stackwgt_mousehideover.cpp

FORMS += \
    mainwindow.ui \
    formsettings.ui \
    dialogaddanime.ui \
    dialogaddmanga.ui \
    dialogaddamv.ui \
    dialogadddorama.ui

HEADERS += \
    mainwindow.h \
    formsettings.h \
    imagecover.h \
    lookprogressbar.h \
    dialogaddanime.h \
    dialogaddmanga.h \
    dialogaddamv.h \
    dialogadddorama.h \
    mngrconnection.h \
    mngrquerys.h \
    stackwgt_mousehideover.h

OTHER_FILES += \
    README.md \
    README_eng.md \
    ToDo.md \
    ChangeLog.md

#win32:RC_FILE += win_icon.rc
#win64:RC_FILE += win_icon.rc

RESOURCES += \
    resource.qrc

TRANSLATIONS += \
    DatabaseAnime_ru.ts \
    DatabaseAnime_en.ts
