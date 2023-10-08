# libalgo

C library with common algorithms, currently ranging search, sort and math.
The algorithms run mostly on a custom i_array struct - a wrapper around an integer array
that provides additional information on size and number of entries.

## Installation

```bash
# build the library
make
# install the library in /usr/include/libalgo
sudo make install
```

## Testing
Tests performed with [criterion](https://github.com/Snaipe/Criterion)

Running the testsuite for algorithms and datastructures
```bash
make test
```
Additional performance test for sorting algorithms
```bash
# build and run the performance test binary
make perf
```
