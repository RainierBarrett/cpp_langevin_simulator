#!/bin/bash
printf "Testing langevin.cpp for coverage...\n"
PROJECT_DIR=~/cpp_langevin_simulator
GCOV_PATH=build/src/CMakeFiles/sharedlib.dir
printf "(gcov files can be found at ${PROJECT_DIR}/${GCOV_PATH})\n"
gcov $PROJECT_DIR/$GCOV_PATH/langevin.cpp.gcov | grep langevin.cpp\' -A1

