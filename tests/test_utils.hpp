#pragma once

#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

// -----------------------------------------------------------------------
//  Minimal test framework
// -----------------------------------------------------------------------

struct TestCase {
    std::string name;
    std::function<void()> fn;
};

struct TestSuite {
    std::string name;
    std::vector<TestCase> cases;
};

static int g_pass = 0;
static int g_fail = 0;

inline void run_suite(const TestSuite &suite) {
    std::cout << "\n=== " << suite.name << " ===\n";
    for (const auto &tc : suite.cases) {
        try {
            tc.fn();
            std::cout << "  [PASS] " << tc.name << "\n";
            ++g_pass;
        } catch (const std::exception &e) {
            std::cout << "  [FAIL] " << tc.name << "\n"
                      << "         " << e.what() << "\n";
            ++g_fail;
        } catch (...) {
            std::cout << "  [FAIL] " << tc.name << "\n"
                      << "         (unknown exception)\n";
            ++g_fail;
        }
    }
}

inline int test_summary() {
    std::cout << "\n----------------------------------------\n";
    std::cout << "Results: " << g_pass << " passed, " << g_fail << " failed\n";
    return g_fail == 0 ? 0 : 1;
}

// -----------------------------------------------------------------------
//  Assertion helpers  (throw on failure so run_suite catches them)
// -----------------------------------------------------------------------

#define ASSERT_TRUE(expr)                                                       \
    do {                                                                        \
        if (!(expr))                                                            \
            throw std::runtime_error(                                           \
                std::string("ASSERT_TRUE failed: " #expr                        \
                            " at " __FILE__ ":") +                              \
                std::to_string(__LINE__));                                       \
    } while (0)

#define ASSERT_FALSE(expr) ASSERT_TRUE(!(expr))

#define ASSERT_EQ(a, b)                                                         \
    do {                                                                        \
        if ((a) != (b))                                                         \
            throw std::runtime_error(                                           \
                std::string("ASSERT_EQ failed: " #a " != " #b                  \
                            " at " __FILE__ ":") +                              \
                std::to_string(__LINE__));                                       \
    } while (0)

#define ASSERT_DOUBLE_EQ(a, b)                                                  \
    do {                                                                        \
        if (std::fabs((a) - (b)) > 1e-9)                                        \
            throw std::runtime_error(                                           \
                std::string("ASSERT_DOUBLE_EQ failed: " #a " != " #b           \
                            " at " __FILE__ ":") +                              \
                std::to_string(__LINE__));                                       \
    } while (0)

#define ASSERT_THROWS(expr, ExcType)                                            \
    do {                                                                        \
        bool caught_ = false;                                                   \
        try { (void)(expr); }                                                   \
        catch (const ExcType &) { caught_ = true; }                             \
        catch (...) {}                                                           \
        if (!caught_)                                                           \
            throw std::runtime_error(                                           \
                std::string("ASSERT_THROWS failed: expected " #ExcType          \
                            " at " __FILE__ ":") +                              \
                std::to_string(__LINE__));                                       \
    } while (0)
