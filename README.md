# NearestPoints Project

This project calculates the closest points on a 3D polyline to a given point. 
The project is built using CMake and includes unit tests powered by GoogleTest.

## Requirements

Before building the project, make sure the following dependencies are installed:

- **CMake** (version 3.10 or higher)
- **C++ compiler** with support for C++17

## Cloning the Repository

```bash
git clone https://github.com/MomsJacket/NearestPoints.git
cd NearestPoints
```
## Building the project

```bash
mkdir build
cd build
cmake ..
make
```

## Runing the project

To run the program, you need to provide a file with polyline points and the coordinates of a point:
./NearestPoints <filename> <x_coord> <y_coord> <z_coord>

For example: ./NearestPoints ../data/example1.txt 2.0 0.5 0.5

## Runing Unit Tests

If you enabled tests during configuration (this is enabled by default), you can run unit tests:
```bash
make test
```

Alternatively, you can run the test binary directly from build/test directory:
```bash
./NearestPoints_tst
```
