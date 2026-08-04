# Contributing to Axion++

Thank you for your interest in contributing! Axion++ is an educational project and welcomes contributions that improve correctness, clarity, or structure.

---

## Getting Started

1. **Fork** the repository and clone your fork locally.
2. Create a **feature branch** from `main`:
   ```bash
   git checkout -b feat/your-feature-name
   ```
3. Make your changes, following the conventions described below.
4. Push your branch and open a **Pull Request** against `main`.

---

## Development Setup

**Requirements:**
- C++20-compatible compiler (GCC 11+, Clang 13+, MSVC 19.29+)
- CMake ≥ 3.20
- Ninja (optional, but recommended)

**Build & test:**
```bash
git clone https://github.com/vk22006/axion-plusplus.git
cd axion-plusplus

cmake -S . -B build -G Ninja
cmake --build build

ctest --test-dir build --output-on-failure
```

---

## Guidelines

### Issues First
Please **open an issue** before starting work on a significant change (new feature, refactor, API change). This avoids duplicate effort and lets us align on design before code is written.

Bug fixes and documentation improvements can go straight to a pull request.

### Coding Style
- Follow the existing code style — modern C++20, no raw pointers, no exceptions from STL types.
- Keep headers in `include/axion/` and implementations in `src/`.
- Every new public function must have a **Doxygen comment** matching the style in [`include/axion/matrix.hpp`](include/axion/matrix.hpp).
- Prefer clarity over cleverness.

### Tests
- Every new feature or bug fix must be accompanied by a corresponding test in `tests/`.
- Add the test executable to the `TESTS` list in [`CMakeLists.txt`](CMakeLists.txt).
- All existing tests must continue to pass.

### Commit Messages
Use [Conventional Commits](https://www.conventionalcommits.org/):

| Prefix | Use for |
|--------|---------|
| `feat:` | New features |
| `fix:` | Bug fixes |
| `docs:` | Documentation only |
| `test:` | Adding or updating tests |
| `refactor:` | Code restructuring without behavior change |
| `bench:` | Benchmark additions or changes |
| `ci:` | CI/workflow changes |
| `chore:` | Maintenance tasks |

Example:
```
feat: add scalar division operator to Matrix
```

### Pull Requests
- Keep PRs focused — one logical change per PR.
- Provide a clear description of what was changed and why.
- Reference any related issue with `Closes #<issue>`.

---

## Project Structure

```text
axion-plusplus/
├── include/axion/     # Public headers
├── src/               # Implementation files
├── tests/             # CTest unit tests
├── benchmarks/        # Performance benchmarks
├── examples/          # Standalone usage examples
├── docs/              # Generated documentation
└── CMakeLists.txt
```

---

## License

By contributing, you agree that your changes will be licensed under the [MIT License](LICENSE).
