cmake_minimum_required(VERSION 3.10)

# Remove when sharing with others.
list(APPEND CMAKE_PREFIX_PATH "/home/jboehme/opt/Qt/Tools/QtCreator")

project(qtc-sourcetrail)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)

find_package(QtCreator COMPONENTS Core CppEditor REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Network REQUIRED)
set(QtX Qt${QT_VERSION_MAJOR})

add_qtc_plugin(Sourcetrail
  PLUGIN_DEPENDS
    QtCreator::Core
    QtCreator::CppEditor
  DEPENDS
    ${QtX}::Widgets
    ${QtX}::Network
    QtCreator::ExtensionSystem
    QtCreator::Utils
  SOURCES
    .github/workflows/build_cmake.yml
    .github/workflows/README.md
    README.md
    src/sourcetrailpluginsettingspage.h
    src/sourcetrailpluginsettingspage.cpp
    src/sourcetrailpluginsettings.h
    src/sourcetrailpluginsettings.cpp
    src/sourcetrailplugin.h
    src/sourcetrailplugin.cpp
    src/sourcetrailconstants.h
    src/sourcetrail_global.h
)
