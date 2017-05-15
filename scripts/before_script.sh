#!/bin/bash

QT_LINK_PREFIX="http://download.qt.io/official_releases/qtcreator/4.2/4.2.0/installer_source"
QT_SRC_FILE="qtcreator_dev.7z"
QT_BIN_FILE="qtcreator.7z"

if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
    QT_SYSTEM_FOLDER="mac_x64"
elif [[ "$TRAVIS_OS_NAME" == "linux" ]]; then
   QT_SYSTEM_FOLDER="linux_gcc_64_rhel66"
fi

curl -fsSL "$QT_LINK_PREFIX/$QT_SYSTEM_FOLDER/$QT_SRC_FILE" -o qt-dev.7z
7z x -y qt-dev.7z -o"qt-src"
curl -fsSL "$QT_LINK_PREFIX/$QT_SYSTEM_FOLDER/$QT_BIN_FILE" -o qt-bin.7z
7z x -y qt-bin.7z -o"qt-bin"
