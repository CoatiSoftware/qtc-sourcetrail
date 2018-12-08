#!/bin/sh

if [ ! -d "qt-src" ]; then
curl -fsSL "http://download.qt.io/official_releases/qtcreator/4.8/4.8.0/installer_source/linux_gcc_64_rhel72/qtcreator_dev.7z" -o qt-dev.7z
7z x -y qt-dev.7z -o"qt-src"
rm qt-dev.7z
fi
if [ ! -d "qt-bin" ]; then
curl -fsSL "http://download.qt.io/official_releases/qtcreator/4.8/4.8.0/installer_source/linux_gcc_64_rhel72/qtcreator.7z" -o qt-bin.7z
7z x -y qt-bin.7z -o"qt-bin"
rm qt-bin.7z
fi

qmake qtc-sourcetrail.pro -r "QTC_SOURCE=qt-src" "QTC_BUILD=qt-bin/lib/qtcreator" "LIBS+=-Lqt-bin/lib/qtcreator" "OUTPUT_PATH=output"
make
