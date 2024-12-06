# Advent of Code 2024 in C++

My solutions to the Advent of Code 2024 (AoC) challenges, using modern C++.


## Build Instructions

First, stage the build-container:

```shell
# create the container image
podman build -t clang:trixie .

# create a build container
podman create --tty --name aoc-build --volume <HOST_PATH>:/AoC clang:trixie /bin/bash
podman start aoc-build
```

In the build-container, initialise the cmake build environment:

```shell
# attach to the build container
podman attach aoc-build

# generate the build environment
cmake -B build -S . -G Ninja -DCMAKE_CXX_COMPILER=clang++-19 -DCMAKE_C_COMPILER=clang-19

# compile all targets
cmake --build build --parallel $(nproc)
```

## Compute Solutions

Advent of Code uses individual puzzle inputs. These inputs are not shared in this repository. You can get your own for free on https://adventofcode.com/.

However, many challenges have examples in their descriptions. These examples are the same for every participant. These examples are available in the **test/** folder.

To run the examples, build the executable for the specific challenge, then supply the file on stdin:

```shell
cmake --build build --target d1p1
./build/d1p1 < test/day-1.txt
```

To run the program on the real puzzle input, download and store it into a file first.
