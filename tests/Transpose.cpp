// Transpose.cpp — tests for Matrix::transpose()

#include "test_utils.hpp"
#include "axion/matrix.hpp"

int main() {
    TestSuite suite{"Transpose"};

    suite.cases.push_back({"transpose of 2x3 matrix has shape 3x2", [] {
        axion::Matrix m({{1, 2, 3}, {4, 5, 6}});
        axion::Matrix t = m.transpose();
        ASSERT_EQ(t.rows_(), 3u);
        ASSERT_EQ(t.cols_(), 2u);
    }});

    suite.cases.push_back({"transpose swaps elements correctly", [] {
        axion::Matrix m({{1, 2, 3}, {4, 5, 6}});
        axion::Matrix t = m.transpose();
        // t[j][i] == m[i][j]
        ASSERT_DOUBLE_EQ(t(0, 0), 1.0);
        ASSERT_DOUBLE_EQ(t(1, 0), 2.0);
        ASSERT_DOUBLE_EQ(t(2, 0), 3.0);
        ASSERT_DOUBLE_EQ(t(0, 1), 4.0);
        ASSERT_DOUBLE_EQ(t(1, 1), 5.0);
        ASSERT_DOUBLE_EQ(t(2, 1), 6.0);
    }});

    suite.cases.push_back({"transpose of square matrix is symmetric", [] {
        axion::Matrix m({{1, 2}, {3, 4}});
        axion::Matrix t = m.transpose();
        ASSERT_DOUBLE_EQ(t(0, 1), m(1, 0));
        ASSERT_DOUBLE_EQ(t(1, 0), m(0, 1));
    }});

    suite.cases.push_back({"double transpose returns original values", [] {
        axion::Matrix m({{1, 2, 3}, {4, 5, 6}});
        axion::Matrix tt = m.transpose().transpose();
        ASSERT_EQ(tt.rows_(), m.rows_());
        ASSERT_EQ(tt.cols_(), m.cols_());
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                ASSERT_DOUBLE_EQ(tt(i, j), m(i, j));
    }});

    suite.cases.push_back({"transpose of identity is identity", [] {
        axion::Matrix I;
        I.identity(3);
        axion::Matrix t = I.transpose();
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                ASSERT_DOUBLE_EQ(t(i, j), I(i, j));
    }});

    run_suite(suite);
    return test_summary();
}
