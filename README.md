
Linux and Mac Builds: [![Build
Status](https://travis-ci.org/CoatiSoftware/qtc-sourcetrail.svg?branch=master)](https://travis-ci.org/CoatiSoftware/qtc-sourcetrail)

Windows Builds: [![Build status](https://ci.appveyor.com/api/projects/status/6luot2mj145ha6j0/branch/master?svg=true)](https://ci.appveyor.com/project/st4ll1/qtc-sourcetrail/branch/master)

# qtc-sourcetrail

Qt Creator Plugin for communication with [Sourcetrail](https://sourcetrail.com)

Supported Qt Creator Versions:
* Qt Creator 4.14.x
* Qt Creator 4.13.x
* Qt Creator 4.12.x
* Qt Creator 4.11.x
* Qt Creator 4.10.x
* Qt Creator 4.9.x
* Qt Creator 4.8.x
* Qt Creator 4.7.x
* Qt Creator 4.6.x
* Qt Creator 4.5.x

## Install

Download the libary from [Releases](https://github.com/CoatiSoftware/qtc-sourcetrail/releases) and put it into the qtcreator plugins folder. To find out where the folder is located please check Help -> System Information... -> PluginsPath

## Settings

### Sourcetrail Settings

In the menu Tools -> Options ... -> Sourcetrail

### Keyboard

In the menu Tools -> Options ... -> Environment -> Keyboard and use the filter to find the Sourcetrail Actions

## Building the Plugin

Run the build.sh script (curl and 7z needed to run) or look into it to see what is needed to build the plugin.

## Creating a new Release

Commit your changes, bump the version number and create a new tag. The CI pipelines will create all the builds and upload them to the new release here on GitHub.



