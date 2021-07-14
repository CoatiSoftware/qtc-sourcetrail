#!/bin/bash

QT_LINK_PREFIX="http://download.qt.io/official_releases/qtcreator/$QTC_VER/$QTC_VER.$QTC_PATCH/installer_source"
QT_SRC_FILE="qtcreator_dev.7z"
QT_BIN_FILE="qtcreator.7z"

curl -fsSL "$QT_LINK_PREFIX/$QTC_DL/$QT_SRC_FILE" -o qt-dev.7z
7z x -y qt-dev.7z -o"qt-src"
curl -fsSL "$QT_LINK_PREFIX/$QTC_DL/$QT_BIN_FILE" -o qt-bin.7z
7z x -y qt-bin.7z -o"qt-bin"

if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
  cd qt-bin && ln -s ./ bin
fi

IFS='.' read -ra QTC_VERS <<< "$QTC_VER"

#Create symlinks without version for qt version >=4.14
if [[ ${QTC_VERS[0]} -gt 3  ]] && [[ ${QTC_VERS[1]} -gt 13  ]]; then
	cd "qt-bin/lib/qtcreator"
	for file in *.so.4; do
		symlink=$(echo "$file" | sed 's/\([^/].so\).4*/\1/')
		ln -s "$file" "$symlink" || true
	done
fi

