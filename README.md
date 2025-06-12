# GenSim

A selection algorithm that combines a deterministic criterion with no false negatives and a probabilistic selection criterion to compute fast and memory-efficient bounds to discard dissimilar pairs.

## Dependencies

GenSim is written in modern C++ and uses [CMake](https://cmake.org/) as its build system. The core algorithm leverages [Sketch](https://github.com/dnbaker/sketch), a high-performance library for probabilistic data structures, bundled directly in the repository under `external/sketch`.

### Required Packages

To compile GenSim, ensure the following packages are installed on your system:

- **CMake ≥ 3.15** – Project configuration and build
- **zlib** – Compression library used internally by Sketch

### Install on Debian/Ubuntu

```bash
sudo apt update
sudo apt install build-essential cmake zlib1g-dev
