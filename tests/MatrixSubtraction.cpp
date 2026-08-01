// MatrixSubtraction.cpp — tests for Matrix::operator-()

#include "test_utils.hpp"
#include "axion/matrix.hpp"
#include "axion/exceptions.hpp"

int main() {
    TestSuite suite{"MatrixSubtraction"};

    suite.cases.push_back({"subtracts two 2x2 matrices correctly", [] {
        axion::Matrix a({{10, 8}, {6, 4}});
        axion::Matrix b({{1,  2}, {3, 4}});
        axion::Matrix c = a - b;
        ASSERT_DOUBLE_EQ(c(0, 0), 9.0);
        ASSERT_DOUBLE_EQ(c(0, 1), 6.0);
        ASSERT_DOUBLE_EQ(c(1, 0), 3.0);
        ASSERT_DOUBLE_EQ(c(1, 1), 0.0);
    }});

    suite.cases.push_back({"subtracting a matrix from itself yields zeros", [] {
        axion::Matrix a({{5, 3}, {-2, 7}});
        axion::Matrix c = a - a;
        ASSERT_DOUBLE_EQ(c(0, 0), 0.0);
        ASSERT_DOUBLE_EQ(c(0, 1), 0.0);
        ASSERT_DOUBLE_EQ(c(1, 0), 0.0);
        ASSERT_DOUBLE_EQ(c(1, 1), 0.0);
    }});

    suite.cases.push_back({"subtracting zero matrix leaves values unchanged", [] {
        axion::Matrix a({{4, -3}, {2, 1}});
        axion::Matrix z(2, 2);
        axion::Matrix c = a - z;
        ASSERT_DOUBLE_EQ(c(0, 0), 4.0);
        ASSERT_DOUBLE_EQ(c(0, 1), -3.0);
        ASSERT_DOUBLE_EQ(c(1, 0), 2.0);
        ASSERT_DOUBLE_EQ(c(1, 1), 1.0);
    }});

    suite.cases.push_back({"result has correct dimensions", [] {
        axion::Matrix a({{1, 2, 3}, {4, 5, 6}});
        axion::Matrix b({{0, 0, 0}, {0, 0, 0}});
        axion::Matrix c = a - b;
        ASSERT_EQ(c.rows_(), 2u);
        ASSERT_EQ(c.cols_(), 3u);
    }});

    suite.cases.push_back({"throws MatrixDimensionError on mismatched sizes", [] {
        axion::Matrix a(3, 2);
        axion::Matrix b(2, 3);
        ASSERT_THROWS(a - b, axion::MatrixDimensionError);
    }});

    run_suite(suite);
    return test_summary();
}
