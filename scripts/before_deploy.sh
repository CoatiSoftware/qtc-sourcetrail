#!/bin/bash

if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
    cd $TRAVIS_BUILD_DIR/output && tar -cf $TRAVIS_BUILD_DIR/qtc-sourcetrail-osx.tar.gz * && cd -
elif [[ "$TRAVIS_OS_NAME" == "linux" ]]; then
    cd $TRAVIS_BUILD_DIR/output && tar -cf $TRAVIS_BUILD_DIR/qtc-sourcetrail-linux.tar.gz * && cd -
fi