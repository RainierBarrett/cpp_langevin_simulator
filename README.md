# cpp_langevin_simulator

![alt text](https://travis-ci.org/RainierBarrett/cpp_langevin_simulator# "build status")

This is a Langevin Dynamics simulator in C++

## Building From Source

First make sure that you have [CMake](http://www.cmake.org/) and an C++ compiler environment installed.

Then open a terminal, go to the source directory and type the following commands:

    $ mkdir build
    $ cd build
    $ cmake ..
    $ make

## Running unit tests

After building this project you may run its unit tests by using these commands:

    $ make test  # To run all tests via CTest
    $ make catch # Run all tests directly, showing more details to you

## License

![GNU GPLv3 Image](https://www.gnu.org/graphics/gplv3-127x51.png)

This program is Free Software: You can use, study share and improve it at your
will. Specifically you can redistribute and/or modify it under the terms of the
[GNU General Public License](https://www.gnu.org/licenses/gpl.html) as
published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.