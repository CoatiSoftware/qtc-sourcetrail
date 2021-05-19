# qtc-sourcetrail

Qt Creator Plugin for communication with [Sourcetrail](https://sourcetrail.com)

Supported Qt Creator Versions:
* Qt Creator 4.15.x

## Install

Download the libary from [Releases](https://github.com/CoatiSoftware/qtc-sourcetrail/releases) and put it into the qtcreator plugins folder. To find out where the folder is located please check Help -> System Information... -> PluginsPath

## Settings

### Sourcetrail Settings

In the menu Tools -> Options ... -> Sourcetrail

### Keyboard

In the menu Tools -> Options ... -> Environment -> Keyboard and use the filter to find the Sourcetrail Actions

## Creating a new Release

Commit your changes, bump the version number and create a new tag. The CI pipelines will create all the builds and upload them to the new release here on GitHub.

## Building the Plugin

Create a build directory and run

    cmake -DCMAKE_PREFIX_PATH=<path_to_qtcreator> -DCMAKE_BUILD_TYPE=RelWithDebInfo <path_to_plugin_source>
    cmake --build .

where `<path_to_qtcreator>` is the relative or absolute path to a Qt Creator build directory, or to a
combined binary and development package (Windows / Linux), or to the `Qt Creator.app/Contents/Resources/`
directory of a combined binary and development package (macOS), and `<path_to_plugin_source>` is the
relative or absolute path to this plugin directory.

## How to Run

Run a compatible Qt Creator with the additional command line argument

    -pluginpath <path_to_plugin>

where `<path_to_plugin>` is the path to the resulting plugin library in the build directory
(`<plugin_build>/lib/qtcreator/plugins` on Windows and Linux,
`<plugin_build>/Qt Creator.app/Contents/PlugIns` on macOS).

You might want to add `-temporarycleansettings` (or `-tcs`) to ensure that the opened Qt Creator
instance cannot mess with your user-global Qt Creator settings.

When building and running the plugin from Qt Creator, you can use

    -pluginpath "%{buildDir}/lib/qtcreator/plugins" -tcs

on Windows and Linux, or

    -pluginpath "%{buildDir}/Qt Creator.app/Contents/PlugIns" -tcs

for the `Command line arguments` field in the run settings.


