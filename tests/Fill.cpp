// Fill.cpp — tests for Matrix::fill()

#include "test_utils.hpp"
#include "axion/matrix.hpp"

int main() {
    TestSuite suite{"Fill"};

    suite.cases.push_back({"fill with zero sets all elements to 0", [] {
        axion::Matrix m(3, 3);
        m.fill(0);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                ASSERT_DOUBLE_EQ(m(i, j), 0.0);
    }});

    suite.cases.push_back({"fill with positive integer", [] {
        axion::Matrix m(2, 4);
        m.fill(7);
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 4; ++j)
                ASSERT_DOUBLE_EQ(m(i, j), 7.0);
    }});

    suite.cases.push_back({"fill with negative integer", [] {
        axion::Matrix m(2, 2);
        m.fill(-5);
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                ASSERT_DOUBLE_EQ(m(i, j), -5.0);
    }});

    suite.cases.push_back({"fill overwrites previous values", [] {
        axion::Matrix m(2, 2);
        m.fill(3);
        m.fill(8);
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                ASSERT_DOUBLE_EQ(m(i, j), 8.0);
    }});

    suite.cases.push_back({"fill non-square matrix", [] {
        axion::Matrix m(1, 5);
        m.fill(42);
        for (int j = 0; j < 5; ++j)
            ASSERT_DOUBLE_EQ(m(0, j), 42.0);
    }});

    run_suite(suite);
    return test_summary();
}
