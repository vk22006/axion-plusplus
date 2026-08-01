// MatrixAddition.cpp — tests for Matrix::operator+()

#include "test_utils.hpp"
#include "axion/matrix.hpp"
#include "axion/exceptions.hpp"

int main() {
    TestSuite suite{"MatrixAddition"};

    suite.cases.push_back({"adds two 2x2 matrices correctly", [] {
        axion::Matrix a({{1, 2}, {3, 4}});
        axion::Matrix b({{5, 6}, {7, 8}});
        axion::Matrix c = a + b;
        ASSERT_DOUBLE_EQ(c(0, 0), 6.0);
        ASSERT_DOUBLE_EQ(c(0, 1), 8.0);
        ASSERT_DOUBLE_EQ(c(1, 0), 10.0);
        ASSERT_DOUBLE_EQ(c(1, 1), 12.0);
    }});

    suite.cases.push_back({"adds negative values correctly", [] {
        axion::Matrix a({{-1, -2}, {-3, -4}});
        axion::Matrix b({{1, 2}, {3, 4}});
        axion::Matrix c = a + b;
        ASSERT_DOUBLE_EQ(c(0, 0), 0.0);
        ASSERT_DOUBLE_EQ(c(1, 1), 0.0);
    }});

    suite.cases.push_back({"adding zero matrix is identity for addition", [] {
        axion::Matrix a({{3, 7}, {-1, 2}});
        axion::Matrix z(2, 2); // zero-initialised
        axion::Matrix c = a + z;
        ASSERT_DOUBLE_EQ(c(0, 0), 3.0);
        ASSERT_DOUBLE_EQ(c(0, 1), 7.0);
        ASSERT_DOUBLE_EQ(c(1, 0), -1.0);
        ASSERT_DOUBLE_EQ(c(1, 1), 2.0);
    }});

    suite.cases.push_back({"result has correct dimensions", [] {
        axion::Matrix a({{1, 2, 3}, {4, 5, 6}});
        axion::Matrix b({{0, 0, 0}, {0, 0, 0}});
        axion::Matrix c = a + b;
        ASSERT_EQ(c.rows_(), 2u);
        ASSERT_EQ(c.cols_(), 3u);
    }});

    suite.cases.push_back({"throws MatrixDimensionError on mismatched sizes", [] {
        axion::Matrix a(2, 3);
        axion::Matrix b(3, 2);
        ASSERT_THROWS(a + b, axion::MatrixDimensionError);
    }});

    run_suite(suite);
    return test_summary();
}
