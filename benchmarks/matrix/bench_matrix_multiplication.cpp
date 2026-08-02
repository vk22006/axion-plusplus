// bench_matrix_multiplication.cpp
// Benchmark for axion::Matrix multiplication (operator*) across various sizes.
//
// Matrix multiplication is O(N^3), so we use fewer iterations for large N to
// keep wall-clock time reasonable.  Results are printed as a table to stdout,
// along with a GFLOP/s estimate (2*N^3 floating-point ops per multiply).

#include <axion/matrix.hpp>

#include <chrono>
#include <string>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

// ── helpers ──────────────────────────────────────────────────────────────────

static axion::matrix make_random(std::size_t rows, std::size_t cols,
                                 std::mt19937 &rng) {
    std::uniform_real_distribution<double> dist(-10.0, 10.0);
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
    double      gflops;     // approximate GFLOP/s based on min time
};

// Scale iterations down for large matrices to avoid excessive runtimes.
static int iterations_for(std::size_t N) {
    if (N <= 64)  return 100;
    if (N <= 128) return 30;
    if (N <= 256) return 10;
    if (N <= 512) return 5;
    return 3;
}

static Result bench_mul(std::size_t N, std::mt19937 &rng) {
    axion::Matrix A(make_random(N, N, rng));
    axion::Matrix B(make_random(N, N, rng));

    int iterations = iterations_for(N);
    double total = 0.0, mn = 1e18, mx = 0.0;

    for (int i = 0; i < iterations; ++i) {
        auto t0 = Clock::now();
        axion::Matrix C = A * B;
        auto t1 = Clock::now();

        double elapsed = Ms(t1 - t0).count();
        total += elapsed;
        if (elapsed < mn) mn = elapsed;
        if (elapsed > mx) mx = elapsed;
    }

    // 2*N^3 flops for a naive NxN matmul
    double flops  = 2.0 * static_cast<double>(N) * N * N;
    double gflops = (flops / 1e9) / (mn / 1e3);   // GFLOP/s from best run

    return {N, total / iterations, mn, mx, gflops};
}

// ── main ─────────────────────────────────────────────────────────────────────

int main() {
    std::mt19937 rng(42);

    const std::vector<std::size_t> sizes = {32, 64, 128, 256, 512};

    std::cout << "=== Matrix Multiplication Benchmark ===\n\n";

    std::cout << std::left
              << std::setw(10) << "Size"
              << std::setw(8)  << "Iters"
              << std::setw(14) << "Avg (ms)"
              << std::setw(14) << "Min (ms)"
              << std::setw(14) << "Max (ms)"
              << std::setw(14) << "GFLOP/s"
              << "\n";
    std::cout << std::string(74, '-') << "\n";

    for (std::size_t N : sizes) {
        Result r = bench_mul(N, rng);
        std::cout << std::left  << std::setw(10) << (std::to_string(N) + "x" + std::to_string(N))
                  << std::setw(8)  << iterations_for(N)
                  << std::fixed << std::setprecision(4)
                  << std::setw(14) << r.avg_ms
                  << std::setw(14) << r.min_ms
                  << std::setw(14) << r.max_ms
                  << std::setprecision(3)
                  << std::setw(14) << r.gflops
                  << "\n";
    }

    return 0;
}
