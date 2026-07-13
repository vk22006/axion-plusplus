# Axion++

> A lightweight neural network library built from scratch in modern C++.

Axion++ is an educational and reusable neural network library designed to explore the fundamentals of deep learning through clean software engineering practices. Rather than relying on existing machine learning frameworks, Axion++ builds every major component from first principles, starting with linear algebra and gradually evolving into a complete neural network library.

The project serves two purposes:

* Learn how neural networks work internally.
* Build a modern C++ library with production-quality project structure, testing, documentation, and continuous integration.

---

## Goals

* Lightweight and dependency-light
* Modern C++ design
* Easy to understand
* Modular architecture
* Educational implementation
* Reusable as a standalone library

---

## Roadmap

### v0.1.0

* Matrix class
* Matrix arithmetic
* Matrix multiplication
* Transpose
* Random initialization
* Matrix serialization
* Unit tests
* Benchmarks
* Documentation

### v0.2.0

* Activation functions

### v0.3.0

* Loss functions

### v0.4.0

* Dense layers
* Forward propagation

### v0.5.0

* Backpropagation

### v0.6.0

* Training engine

### v0.7.0

* Model serialization

### v0.8.0

* Dataset utilities

### v0.9.0

* Examples and documentation improvements

### v1.0.0

* Stable lightweight neural network library

---

## Project Structure

```text
Axion++/
│
├── include/
│   └── axion/
├── src/
├── tests/
├── benchmarks/
├── examples/
├── docs/
└── CMakeLists.txt
```

---

## Building

```bash
git clone https://github.com/vk22006/axion-plusplus.git

cd axion-plusplus

cmake -B build

cmake --build build
```

---

## Example

```cpp
#include <axion/matrix.hpp>

using namespace axion;

int main()
{
    Matrix A({
        {1, 2},
        {3, 4}
    });

    Matrix B({
        {5, 6},
        {7, 8}
    });

    Matrix C = A * B;

    C.print();
}
```

## Long-Term Vision

Axion++ is intended to grow incrementally while remaining lightweight and approachable.

Planned capabilities include:

* Dense neural networks
* Multiple activation functions
* Gradient descent optimization
* Backpropagation
* Model persistence
* Dataset utilities
* Training and evaluation pipeline

The project intentionally prioritizes clarity and maintainability over feature count.

<!-- ## Testing

Every core module is accompanied by automated unit tests to verify correctness.

```bash
ctest
```

--- -->

<!-- ## Benchmarks

Performance benchmarks are included for major matrix operations such as:

* Addition
* Multiplication
* Transpose -->

## Documentation

Documentation can be found inside the `docs/` directory and will expand with each release.


## Technologies

* Modern C++
* CMake
* GitHub Actions
* Google Test (planned)
* Google Benchmark (planned)

## Contributing

Contributions, bug reports, and suggestions are welcome.

Please open an issue before submitting significant changes.

## License

This project is licensed under the MIT License.

## Project Status

**Current Version:** `v0.1.0 (In Development)`

Axion++ is under active development. The current milestone focuses on building a robust and efficient Matrix library that will serve as the foundation for the neural network engine.
