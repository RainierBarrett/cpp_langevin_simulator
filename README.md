# cpp_langevin_simulator

##Current Code Coverage
100.00%

[![Build Status](https://travis-ci.org/RainierBarrett/cpp_langevin_simulator.svg?branch=master)](https://travis-ci.org/RainierBarrett/cpp_langevin_simulator)

This is a Langevin Dynamics simulator in C++

## Building From Source

First make sure that you have [CMake](http://www.cmake.org/) and a C++ compiler environment installed.

Then open a terminal, go to the source directory and type the following commands:

    $ mkdir build
    $ cd build
    $ cmake ..
    $ make

## Running unit tests

After building this project you may run its unit tests by using these commands:

    $ make test  # To run all tests via CTest
    $ make catch # Run all tests directly, showing more details to you

Right now the tests are set to run all and reports all at once, too. Use catch to see if an individual test is failing. Right now what I've got covered for testing is as follows:

    * `read_test.cpp` : This tests whether the file-reader is reading a sample file appropriately
    * `eta_test.cpp`  : This tests whether my random process (eta) is giving different numbers whenever it's called.
    * `get_pos_test.cpp` : This makes sure the index-grabbing function works appropriately.
    * `setup_test.cpp` : This tests that all the set-value functions for the Langevin class are working.
    * `timestep_test.cpp` : This makes sure that the particle's position moves when the `step()` function is called.

## Checking code coverage

For now, I've been unable to convince Travis to play nice with an automated test for this. To see it for yourself, you'll have to run a command. From within the build directory, you can run:

    $make coverage

This will run gcov on the Langevin cpp file, and report the code coverage to the terminal.

## TODO

   * Write a test and function to print trajectory to file
   * Possibly: write a test and function for a better, less granular force-finder (interpolator).
   * Do some integrated testing.

## License

![GNU GPLv3 Image](https://www.gnu.org/graphics/gplv3-127x51.png)

This program is Free Software: You can use, study share and improve it at your
will. Specifically you can redistribute and/or modify it under the terms of the
[GNU General Public License](https://www.gnu.org/licenses/gpl.html) as
published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.