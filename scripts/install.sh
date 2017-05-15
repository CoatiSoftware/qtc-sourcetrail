#!/bin/sh

if [[ $BUILD_OS_NAME == "osx" ]]; then
    brew install qt5
    brew link --force qt5
elif [[ $BUILD_OS_NAME == "linux" ]]; then
    sudo apt-get install -qq qt5-default qttools5-dev-tools p7zip-full
    sudo apt-get update -qq
fi