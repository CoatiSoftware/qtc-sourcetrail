#!/bin/bash

QT_LINK_PREFIX="http://download.qt.io/official_releases/qtcreator/$QTC_VER/$QTC_VER.0/installer_source"
QT_SRC_FILE="qtcreator_dev.7z"
QT_BIN_FILE="qtcreator.7z"

curl -fsSL "$QT_LINK_PREFIX/$QTC_DL/$QT_SRC_FILE" -o qt-dev.7z
7z x -y qt-dev.7z -o"qt-src"
curl -fsSL "$QT_LINK_PREFIX/$QTC_DL/$QT_BIN_FILE" -o qt-bin.7z
7z x -y qt-bin.7z -o"qt-bin"

if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
  cd qt-bin && ln -s ./ bin
fi