// bench_matrix_transpose.cpp
// Benchmark for axion::Matrix::transpose() across various sizes.
//
// Transpose is O(N^2) memory-bandwidth bound. We benchmark both square and
// rectangular matrices so cache effects are visible.  Results include an
// effective memory bandwidth estimate (two NxM arrays read+written).

#include <axion/matrix.hpp>

#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

// ── helpers ──────────────────────────────────────────────────────────────────

static axion::matrix make_random(std::size_t rows, std::size_t cols,
                                 std::mt19937 &rng) {
    std::uniform_real_distribution<double> dist(-50.0, 50.0);
    axion::matrix m(rows, std::vector<double>(cols));
    for (auto &row : m)
        for (auto &v : row)
            v = dist(rng);
    return m;
}

using Clock = std::chrono::high_resolution_clock;
using Ms    = std::chrono::duration<double, std::milli>;

// ── benchmark ────────────────────────────────────────────────────────────────

struct Shape { std::size_t rows, cols; };

struct Result {
    Shape  shape;
    double avg_ms;
    double min_ms;
    double max_ms;
    double bandwidth_gb_s;  // estimated effective bandwidth (GB/s) from best run
};

static Result bench_transpose(Shape shape, int iterations, std::mt19937 &rng) {
    axion::Matrix A(make_random(shape.rows, shape.cols, rng));

    double total = 0.0, mn = 1e18, mx = 0.0;

    for (int i = 0; i < iterations; ++i) {
        auto t0 = Clock::now();
        axion::Matrix T = A.transpose();
        auto t1 = Clock::now();

        double elapsed = Ms(t1 - t0).count();
        total += elapsed;
        if (elapsed < mn) mn = elapsed;
        if (elapsed > mx) mx = elapsed;
    }

    // Estimate: read NxM doubles + write MxN doubles (2 * N*M * 8 bytes)
    double bytes      = 2.0 * shape.rows * shape.cols * sizeof(double);
    double bandwidth  = (bytes / 1e9) / (mn / 1e3);   // GB/s from best run

    return {shape, total / iterations, mn, mx, bandwidth};
}

// ── main ─────────────────────────────────────────────────────────────────────

int main() {
    std::mt19937 rng(42);

    // Mix of square and rectangular shapes
    const std::vector<Shape> shapes = {
        {32,   32},
        {64,   64},
        {128,  128},
        {256,  256},
        {512,  512},
        {1024, 1024},
        {512,  1024},   // wide rectangle
        {1024, 512},    // tall rectangle
    };
    constexpr int ITERATIONS = 100;

    std::cout << "=== Matrix Transpose Benchmark ===\n";
    std::cout << "Iterations per shape: " << ITERATIONS << "\n\n";

    std::cout << std::left
              << std::setw(16) << "Shape"
              << std::setw(14) << "Avg (ms)"
              << std::setw(14) << "Min (ms)"
              << std::setw(14) << "Max (ms)"
              << std::setw(14) << "BW (GB/s)"
              << "\n";
    std::cout << std::string(72, '-') << "\n";

    for (const Shape &s : shapes) {
        Result r = bench_transpose(s, ITERATIONS, rng);
        std::string label = std::to_string(s.rows) + "x" + std::to_string(s.cols);
        std::cout << std::left  << std::setw(16) << label
                  << std::fixed << std::setprecision(4)
                  << std::setw(14) << r.avg_ms
                  << std::setw(14) << r.min_ms
                  << std::setw(14) << r.max_ms
                  << std::setprecision(3)
                  << std::setw(14) << r.bandwidth_gb_s
                  << "\n";
    }

    return 0;
}
