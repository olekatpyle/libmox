# libmox

Personal C library for all sorts of algorithms and datastructures,
mainly meant to be reference implementations and/or serve an educational purpose.

The library is actively developed on Linux x86_64, and only tested on Linux.
Currently no warranty that the library builds on other systems.

## Installation
All following commands should be executed at the root of the repository.

```bash
# build the library
# the output shared object and static archive library can be found in /lib
# inside the repository
make

# clean the repository from all build artifacts
make clean

# install the library in /lib of your system and the header files in /usr/include/libmox
sudo make install

# reverse the install step, in other words uninstall the library from your system
sudo make uninstall
```

## Testing
Tests are performed with criterion. In order to run the unit tests, you need to have installed libcriterion.
See https://github.com/Snaipe/Criterion for instructions, on how
to install the library on your system. Note, that only the unit tests are build
with criterion. You still can build the performance test.

Running the testsuite for algorithms and datastructures
```bash
make test
```
Additional performance test for sorting algorithms
```bash

# build and run the performance test binary
make perf

# you can specify, how many runs the test should make by specifying the LOOPS variable
make perf LOOPS=10
```

## Implemented

### Math algorithms
- Advanced euklidean algorithm
- Recursive calculation of factorial
- Recursive calculation of fibonacci numbers
- Recursive calculation of greatest common divisor

### Sorting algorithms
- Bubblesort
- Insertionsort
- Mergesort
- Quicksort
- Selectionsort

### Search
- Recursive binary search

### Data structures
- int32 linked list wrapper `ì_array`
