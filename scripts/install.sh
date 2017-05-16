#!/bin/bash

if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
    brew install p7zip
    # brew install wget
    brew install qt
    brew link --force qt
    rvm get stable
    rvm use ruby-2.0.0-p648
elif [[ "$TRAVIS_OS_NAME" == "linux" ]]; then
    sudo apt-get install -qq qt5-default qttools5-dev-tools p7zip-full
    sudo apt-get update -qq
fi