# PLD_COMP
[![Build Status](https://travis-ci.org/heptastique/PLD_COMP.svg?branch=master)](https://travis-ci.org/heptastique/PLD_COMP)

## How to compile on linux
- Install [CMake](https://cmake.org/download/) if not done.
- Install uuid if not done
```
$ sudo apt-get install uuid-dev 
```
- Run the application (Creates Assembly)
```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
$ cd ..
$ mkdir -p target
$ ./bin/app <target_file.c>
```
- Compile and Run Assembly
```bash
$ ./scripts/compile.sh
$ ./target/prog.out
```
