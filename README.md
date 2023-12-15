## Intro
C++ utils library.

## CI Status
[![CI](https://github.com/nkh-lab/cpp-utils/actions/workflows/ci.yml/badge.svg)](https://github.com/nkh-lab/cpp-utils/actions/workflows/ci.yml)

Ubuntu | Windows

## How to build
### Linux
```
mkdir build && cd build
cmake ..
make
```
Debug and Unit Tests:
```
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug -Dlibcpputils_BUILD_UTESTS=ON ..
make
```