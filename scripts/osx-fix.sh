#!/bin/bash

PLUGINPATH="${1}"

otool -l "${PLUGINPATH}" | grep -e "name .*/Qt.*" | cut -d' ' -f 11 | sed "p;s|.*\(Qt.*\.framework\)|@rpath\/Frameworks\/\1|;s|$| \"${PLUGINPATH}\"|" | paste -d' ' - - | xargs -L 1 install_name_tool -change 

