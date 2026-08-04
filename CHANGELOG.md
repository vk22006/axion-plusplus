# Changelog

All notable changes to Axion++ are documented in this file.

The format follows [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

---

## [0.1.0] — 2026-08-03

### Added

#### Matrix
- `Matrix` class with full two-dimensional matrix support
- Zero-initialized constructor `Matrix(rows, cols)`
- Constructor from existing `axion::matrix` (`std::vector<std::vector<double>>`)
- Identity matrix initializer via `identity(dimension)`
- Fill matrix with constant value via `fill(val)`
- Matrix–matrix arithmetic: `operator+`, `operator-`, `operator*`
- Scalar arithmetic: `operator+`, `operator-`, `operator*`, `operator/`
- Transpose via `transpose()`
- Element access via `operator()(i, j)`
- Equality and inequality comparison: `operator==`, `operator!=`
- Row and column accessors: `rows_()`, `cols_()`
- Stream I/O: `operator>>`, `operator<<`

#### Exceptions
- `AxionError` — base exception for all axion errors
- `MatrixDimensionError` — incompatible matrix shapes for an operation
- `InvalidIndexError` — out-of-bounds element access
- `InvalidShapeError` — malformed matrix construction
- `DivisionByZeroError` — scalar division by zero

#### Project Infrastructure
- CMake build system (CMake ≥ 3.20, C++20)
- Nine automated unit tests via CTest:
  `MatrixConstruction`, `Identity`, `Fill`, `MatrixAddition`,
  `MatrixSubtraction`, `MatrixMultiplication`, `ScalarOperations`,
  `Transpose`, `Equality`
- GitHub Actions CI workflow (build + test on `ubuntu-latest`)
- Four example programs: `matrix_demo`, `transpose_matrix`,
  `scalar_operations`, `matrix_multiplication`
- Three matrix performance benchmarks:
  `bench_matrix_addition`, `bench_matrix_multiplication`,
  `bench_matrix_transpose`
- Doxygen documentation configuration
- MIT License

---

## [Unreleased]

### Planned
- Dense (fully-connected) layer
- Activation functions (ReLU, Sigmoid, Tanh)
- Loss functions (MSE, Cross-Entropy)
- Gradient descent optimizer
- Backpropagation engine
- Model save / load
- Dataset utilities
- Training and evaluation pipeline
