QT += gui network

CONFIG += include_source_dir
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

DEFINES += SOURCETRAIL_LIBRARY
DEFINES += VERSION_MINOR=$$QTC_VER_MINOR
DEFINES += VERSION_MAJOR=$$QTC_VER_MAJOR

# QtCreatorSourcetrail files
TARGET = Sourcetrail

SOURCES += \
    src/sourcetrailpluginsettingspage.cpp \
    src/sourcetrailpluginsettings.cpp \
    src/sourcetrailplugin.cpp

HEADERS += \
    src/sourcetrailpluginsettingspage.h \
    src/sourcetrailpluginsettings.h \
    src/sourcetrailplugin.h \
    src/sourcetrailconstants.h \
    src/sourcetrail_global.h

# Qt Creator linking

## Either set the IDE_SOURCE_TREE when running qmake,
## or set the QTC_SOURCE environment variable, to override the default setting
isEmpty(IDE_SOURCE_TREE): IDE_SOURCE_TREE = $$QTC_SOURCE
isEmpty(IDE_SOURCE_TREE): IDE_SOURCE_TREE = "/home/st4ll1/dev/qt-creator"

## Either set the IDE_BUILD_TREE when running qmake,
## or set the QTC_BUILD environment variable, to override the default setting
isEmpty(IDE_BUILD_TREE): IDE_BUILD_TREE = $$QTC_BUILD
isEmpty(IDE_BUILD_TREE): IDE_BUILD_TREE = "/home/st4ll1/dev/qt-creator"

## uncomment to build plugin into user config directory
## <localappdata>/plugins/<ideversion>
##    where <localappdata> is e.g.
##    "%LOCALAPPDATA%\QtProject\qtcreator" on Windows Vista and later
##    "$XDG_DATA_HOME/data/QtProject/qtcreator" or "~/.local/share/data/QtProject/qtcreator" on Linux
##    "~/Library/Application Support/QtProject/Qt Creator" on OS X
# USE_USER_DESTDIR = yes

###### If the plugin can be depended upon by other plugins, this code needs to be outsourced to
###### <dirname>_dependencies.pri, where <dirname> is the name of the directory containing the
###### plugin's sources.

LIBS += -L$$IDE_PLUGIN_PATH/QtProject \
        -L$$IDE_BUILD_TREE \
        -L$$IDE_BUILD_TREE/plugins/QtProject \
        -L$$IDE_BUILD_TREE/plugins

QTC_PLUGIN_NAME = Sourcetrail
QTC_LIB_DEPENDS += \
    # nothing here at this time

QTC_PLUGIN_DEPENDS += \
    coreplugin \
    cppeditor

QTC_PLUGIN_RECOMMENDS += \
    # optional plugin dependencies. nothing here at this time

###### End _dependencies.pri contents ######

#Check version cause after 4.13 structure slightly changed
greaterThan(QTC_VER_MINOR, 13) | greaterThan(QTC_VER_MAJOR, 4){
    include($$IDE_SOURCE_TREE/include/src/qtcreatorplugin.pri)
}

lessThan(QTC_VER_MINOR, 13) | lessThan(QTC_VER_MAJOR, 4){
    include($$IDE_SOURCE_TREE/src/qtcreatorplugin.pri)
}

FORMS += \
    src/sourcetrailpluginsettingspage.ui

RESOURCES += sourcetrail.qrc

DISTFILES += \
    Sourcetrail.json.in

!isEmpty(OUTPUT_PATH) {
    DESTDIR = $$OUTPUT_PATH
    message("You set output path to $$DESTDIR")
}
