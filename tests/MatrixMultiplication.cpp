// MatrixMultiplication.cpp — tests for Matrix::operator*(Matrix)

#include "test_utils.hpp"
#include "axion/matrix.hpp"
#include "axion/exceptions.hpp"

int main() {
    TestSuite suite{"MatrixMultiplication"};

    suite.cases.push_back({"multiplies two 2x2 matrices correctly", [] {
        axion::Matrix a({{1, 2}, {3, 4}});
        axion::Matrix b({{5, 6}, {7, 8}});
        axion::Matrix c = a * b;
        // [1*5+2*7, 1*6+2*8] = [19, 22]
        // [3*5+4*7, 3*6+4*8] = [43, 50]
        ASSERT_DOUBLE_EQ(c(0, 0), 19.0);
        ASSERT_DOUBLE_EQ(c(0, 1), 22.0);
        ASSERT_DOUBLE_EQ(c(1, 0), 43.0);
        ASSERT_DOUBLE_EQ(c(1, 1), 50.0);
    }});

    suite.cases.push_back({"multiplies rectangular matrices (2x3) * (3x2) -> 2x2", [] {
        axion::Matrix a({{1, 2, 3}, {4, 5, 6}});
        axion::Matrix b({{7, 8}, {9, 10}, {11, 12}});
        axion::Matrix c = a * b;
        ASSERT_EQ(c.rows_(), 2u);
        ASSERT_EQ(c.cols_(), 2u);
        // [1*7+2*9+3*11, 1*8+2*10+3*12] = [58, 64]
        // [4*7+5*9+6*11, 4*8+5*10+6*12] = [139, 154]
        ASSERT_DOUBLE_EQ(c(0, 0), 58.0);
        ASSERT_DOUBLE_EQ(c(0, 1), 64.0);
        ASSERT_DOUBLE_EQ(c(1, 0), 139.0);
        ASSERT_DOUBLE_EQ(c(1, 1), 154.0);
    }});

    suite.cases.push_back({"multiplying by identity yields original matrix", [] {
        axion::Matrix a({{2, 3}, {4, 5}});
        axion::Matrix I;
        I.identity(2);
        axion::Matrix c = a * I;
        ASSERT_DOUBLE_EQ(c(0, 0), 2.0);
        ASSERT_DOUBLE_EQ(c(0, 1), 3.0);
        ASSERT_DOUBLE_EQ(c(1, 0), 4.0);
        ASSERT_DOUBLE_EQ(c(1, 1), 5.0);
    }});

    suite.cases.push_back({"multiplying by zero matrix yields zero matrix", [] {
        axion::Matrix a({{3, 7}, {-1, 4}});
        axion::Matrix z(2, 2);
        axion::Matrix c = a * z;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                ASSERT_DOUBLE_EQ(c(i, j), 0.0);
    }});

    suite.cases.push_back({"throws MatrixDimensionError on incompatible shapes", [] {
        axion::Matrix a(2, 3);
        axion::Matrix b(2, 3); // cols(a)=3 != rows(b)=2
        ASSERT_THROWS(a * b, axion::MatrixDimensionError);
    }});

    run_suite(suite);
    return test_summary();
}
