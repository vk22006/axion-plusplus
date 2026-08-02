// bench_matrix_addition.cpp
// Benchmark for axion::Matrix addition across various sizes.
//
// For each size N, creates two NxN matrices filled with random values and
// times how long operator+ takes over ITERATIONS repetitions.  Results are
// printed as a table to stdout.

#include <axion/matrix.hpp>

#include <chrono>
#include <string>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

// ── helpers ──────────────────────────────────────────────────────────────────

static axion::matrix make_random(std::size_t rows, std::size_t cols,
                                 std::mt19937 &rng) {
    std::uniform_real_distribution<double> dist(-100.0, 100.0);
    axion::matrix m(rows, std::vector<double>(cols));
    for (auto &row : m)
        for (auto &v : row)
            v = dist(rng);
    return m;
}

using Clock = std::chrono::high_resolution_clock;
using Ms    = std::chrono::duration<double, std::milli>;

// ── benchmark ────────────────────────────────────────────────────────────────

struct Result {
    std::size_t size;
    double      avg_ms;
    double      min_ms;
    double      max_ms;
};

static Result bench_add(std::size_t N, int iterations, std::mt19937 &rng) {
    axion::Matrix A(make_random(N, N, rng));
    axion::Matrix B(make_random(N, N, rng));

    double total = 0.0, mn = 1e18, mx = 0.0;

    for (int i = 0; i < iterations; ++i) {
        auto t0 = Clock::now();
        axion::Matrix C = A + B;
        auto t1 = Clock::now();

        double elapsed = Ms(t1 - t0).count();
        total += elapsed;
        if (elapsed < mn) mn = elapsed;
        if (elapsed > mx) mx = elapsed;
    }

    return {N, total / iterations, mn, mx};
}

// ── main ─────────────────────────────────────────────────────────────────────

int main() {
    std::mt19937 rng(42);

    // Matrix sizes to benchmark
    const std::vector<std::size_t> sizes = {32, 64, 128, 256, 512, 1024};
    constexpr int ITERATIONS = 50;

    std::cout << "=== Matrix Addition Benchmark ===\n";
    std::cout << "Iterations per size: " << ITERATIONS << "\n\n";

    std::cout << std::left
              << std::setw(10) << "Size"
              << std::setw(14) << "Avg (ms)"
              << std::setw(14) << "Min (ms)"
              << std::setw(14) << "Max (ms)"
              << "\n";
    std::cout << std::string(52, '-') << "\n";

    for (std::size_t N : sizes) {
        Result r = bench_add(N, ITERATIONS, rng);
        std::cout << std::left  << std::setw(10) << (std::to_string(N) + "x" + std::to_string(N))
                  << std::fixed << std::setprecision(4)
                  << std::setw(14) << r.avg_ms
                  << std::setw(14) << r.min_ms
                  << std::setw(14) << r.max_ms
                  << "\n";
    }

    return 0;
}
