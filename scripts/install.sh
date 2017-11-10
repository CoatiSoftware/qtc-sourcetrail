#!/bin/bash

if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
    brew update
    brew install p7zip
    brew install qt
    brew link --force qt
elif [[ "$TRAVIS_OS_NAME" == "linux" ]]; then
    sudo apt-get install -qq qt5-default qttools5-dev-tools p7zip-full
    sudo apt-get update -qq
fi