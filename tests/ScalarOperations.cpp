// ScalarOperations.cpp — tests for Matrix scalar operators (+, -, *, /)

#include "test_utils.hpp"
#include "axion/matrix.hpp"
#include "axion/exceptions.hpp"

int main() {
    TestSuite suite{"ScalarOperations"};

    // ── operator+(int) ───────────────────────────────────────────────────
    suite.cases.push_back({"scalar addition adds to every element", [] {
        axion::Matrix m({{1, 2}, {3, 4}});
        axion::Matrix r = m + 10;
        ASSERT_DOUBLE_EQ(r(0, 0), 11.0);
        ASSERT_DOUBLE_EQ(r(0, 1), 12.0);
        ASSERT_DOUBLE_EQ(r(1, 0), 13.0);
        ASSERT_DOUBLE_EQ(r(1, 1), 14.0);
    }});

    suite.cases.push_back({"scalar addition with zero leaves matrix unchanged", [] {
        axion::Matrix m({{5, -3}, {7, 0}});
        axion::Matrix r = m + 0;
        ASSERT_DOUBLE_EQ(r(0, 0), 5.0);
        ASSERT_DOUBLE_EQ(r(0, 1), -3.0);
    }});

    // ── operator-(int) ───────────────────────────────────────────────────
    suite.cases.push_back({"scalar subtraction subtracts from every element", [] {
        axion::Matrix m({{10, 20}, {30, 40}});
        axion::Matrix r = m - 5;
        ASSERT_DOUBLE_EQ(r(0, 0), 5.0);
        ASSERT_DOUBLE_EQ(r(0, 1), 15.0);
        ASSERT_DOUBLE_EQ(r(1, 0), 25.0);
        ASSERT_DOUBLE_EQ(r(1, 1), 35.0);
    }});

    suite.cases.push_back({"scalar subtraction with negative scalar", [] {
        axion::Matrix m({{1, 2}, {3, 4}});
        axion::Matrix r = m - (-3);
        ASSERT_DOUBLE_EQ(r(0, 0), 4.0);
        ASSERT_DOUBLE_EQ(r(1, 1), 7.0);
    }});

    // ── operator*(int) ───────────────────────────────────────────────────
    suite.cases.push_back({"scalar multiplication scales every element", [] {
        axion::Matrix m({{1, 2}, {3, 4}});
        axion::Matrix r = m * 3;
        ASSERT_DOUBLE_EQ(r(0, 0), 3.0);
        ASSERT_DOUBLE_EQ(r(0, 1), 6.0);
        ASSERT_DOUBLE_EQ(r(1, 0), 9.0);
        ASSERT_DOUBLE_EQ(r(1, 1), 12.0);
    }});

    suite.cases.push_back({"scalar multiplication by zero yields zero matrix", [] {
        axion::Matrix m({{5, 7}, {-3, 2}});
        axion::Matrix r = m * 0;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                ASSERT_DOUBLE_EQ(r(i, j), 0.0);
    }});

    suite.cases.push_back({"scalar multiplication by one leaves matrix unchanged", [] {
        axion::Matrix m({{4, -1}, {0, 9}});
        axion::Matrix r = m * 1;
        ASSERT_DOUBLE_EQ(r(0, 0), 4.0);
        ASSERT_DOUBLE_EQ(r(0, 1), -1.0);
        ASSERT_DOUBLE_EQ(r(1, 0), 0.0);
        ASSERT_DOUBLE_EQ(r(1, 1), 9.0);
    }});

    // ── operator/(int) ───────────────────────────────────────────────────
    suite.cases.push_back({"scalar division divides every element", [] {
        axion::Matrix m({{10, 20}, {30, 40}});
        axion::Matrix r = m / 10;
        ASSERT_DOUBLE_EQ(r(0, 0), 1.0);
        ASSERT_DOUBLE_EQ(r(0, 1), 2.0);
        ASSERT_DOUBLE_EQ(r(1, 0), 3.0);
        ASSERT_DOUBLE_EQ(r(1, 1), 4.0);
    }});

    suite.cases.push_back({"scalar division by negative divisor", [] {
        axion::Matrix m({{-6, 4}, {2, -8}});
        axion::Matrix r = m / (-2);
        ASSERT_DOUBLE_EQ(r(0, 0), 3.0);
        ASSERT_DOUBLE_EQ(r(0, 1), -2.0);
        ASSERT_DOUBLE_EQ(r(1, 0), -1.0);
        ASSERT_DOUBLE_EQ(r(1, 1), 4.0);
    }});

    suite.cases.push_back({"scalar division by zero throws DivisionByZeroError", [] {
        axion::Matrix m({{1, 2}, {3, 4}});
        ASSERT_THROWS(m / 0, axion::DivisionByZeroError);
    }});

    run_suite(suite);
    return test_summary();
}
