#!/bin/bash
printf "Testing langevin.cpp for coverage...\n"
PROJECT_DIR=~/cpp_langevin_simulator
GCOV_PATH=build/src/CMakeFiles/sharedlib.dir
printf "(gcov files can be found at ${PROJECT_DIR}/${GCOV_PATH})\n"
gcov $PROJECT_DIR/$GCOV_PATH/langevin.cpp.gcov -n | grep langevin.cpp\' -A1
PERCENT=`gcov $PROJECT_DIR/$GCOV_PATH/langevin.cpp.gcov -n | grep langevin.cpp -A1| grep "[0-9]\+\.[0-9]\+\?" -o`
sed -i -e "s/[0-9]\+\.[0-9]\+\%/${PERCENT}%/g" README.md

