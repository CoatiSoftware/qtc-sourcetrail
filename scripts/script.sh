#!/bin/bash

IFS='.' read -ra QTC_VERS <<< "$QTC_VER"

if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
    qmake qtc-sourcetrail.pro -r "QTC_VER_MAJOR=${QTC_VERS[0]}" "QTC_VER_MINOR=${QTC_VERS[1]}" "QTC_SOURCE=$TRAVIS_BUILD_DIR/qt-src" "QTC_BUILD=$TRAVIS_BUILD_DIR/qt-bin" "LIBS+=-L$TRAVIS_BUILD_DIR/qt-bin" "OUTPUT_PATH=$TRAVIS_BUILD_DIR/output"
elif [[ "$TRAVIS_OS_NAME" == "linux" ]]; then
    qmake qtc-sourcetrail.pro -r "QTC_VER_MAJOR=${QTC_VERS[0]}" "QTC_VER_MINOR=${QTC_VERS[1]}" "QTC_SOURCE=$TRAVIS_BUILD_DIR/qt-src" "QTC_BUILD=$TRAVIS_BUILD_DIR/qt-bin/lib/qtcreator" "LIBS+=-L$TRAVIS_BUILD_DIR/qt-bin/lib/qtcreator" "OUTPUT_PATH=$TRAVIS_BUILD_DIR/output"
fi

make