# GenSim

A selection algorithm that combines a deterministic criterion with no false negatives and a probabilistic selection criterion to compute fast and memory-efficient bounds to discard dissimilar pairs.

## Dependencies

GenSim is written in modern C++ and uses [CMake](https://cmake.org/) as its build system. The core algorithm leverages [Sketch](https://github.com/dnbaker/sketch), a high-performance library for probabilistic data structures, bundled directly in the repository under `external/sketch`.

### Required Packages

To compile GenSim, ensure the following packages are installed on your system:

- **CMake ≥ 3.15** – Project configuration and build
- **zlib** – Compression library used internally by Sketch

## Build and Run Demo

To build the project, run the following commands from the root directory:

```bash
cmake -S . -B build
cmake --build build
```
To run the demo:

```bash
./build/demo <p>
```

`<p>` is an integer representing the precision parameter for the HyperLogLog sketch.

It must be between 2 and 16 (inclusive). Values outside this range will be rejected at runtime.