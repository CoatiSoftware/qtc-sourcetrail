#!/bin/bash

if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
    cd $TRAVIS_BUILD_DIR/output && zip -r $TRAVIS_BUILD_DIR/qtc-sourcetrail-osx * && cd -
elif [[ "$TRAVIS_OS_NAME" == "linux" ]]; then
    cd $TRAVIS_BUILD_DIR/output && zip -r $TRAVIS_BUILD_DIR/qtc-sourcetrail-linux * && cd -
fi