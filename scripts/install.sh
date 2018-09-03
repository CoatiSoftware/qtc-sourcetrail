#!/bin/bash

if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
    brew update
    brew install p7zip
    brew install qt
    brew link --force qt
elif [[ "$TRAVIS_OS_NAME" == "linux" ]]; then
	sudo apt-get update
	sudo apt-get install apt=1.2.10
	sudo apt-get clean
	sudo rm -rf /var/lib/apt/lists
	sudo apt-get update
    sudo apt-get install -qq qt5-default qttools5-dev-tools p7zip-full
    sudo apt-get update -qq
fi