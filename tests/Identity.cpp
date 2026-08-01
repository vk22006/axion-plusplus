// Identity.cpp — tests for Matrix::identity()

#include "test_utils.hpp"
#include "axion/matrix.hpp"
#include "axion/exceptions.hpp"

int main() {
    TestSuite suite{"Identity"};

    suite.cases.push_back({"1x1 identity matrix", [] {
        axion::Matrix m;
        m.identity(1);
        ASSERT_EQ(m.rows_(), 1u);
        ASSERT_EQ(m.cols_(), 1u);
        ASSERT_DOUBLE_EQ(m(0, 0), 1.0);
    }});

    suite.cases.push_back({"3x3 diagonal is all ones", [] {
        axion::Matrix m;
        m.identity(3);
        ASSERT_EQ(m.rows_(), 3u);
        ASSERT_EQ(m.cols_(), 3u);
        for (int i = 0; i < 3; ++i)
            ASSERT_DOUBLE_EQ(m(i, i), 1.0);
    }});

    suite.cases.push_back({"3x3 off-diagonal is all zeros", [] {
        axion::Matrix m;
        m.identity(3);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (i != j)
                    ASSERT_DOUBLE_EQ(m(i, j), 0.0);
    }});

    suite.cases.push_back({"identity overwrites existing data", [] {
        axion::Matrix m(2, 2);
        m.fill(9);
        m.identity(2);
        ASSERT_DOUBLE_EQ(m(0, 0), 1.0);
        ASSERT_DOUBLE_EQ(m(0, 1), 0.0);
        ASSERT_DOUBLE_EQ(m(1, 0), 0.0);
        ASSERT_DOUBLE_EQ(m(1, 1), 1.0);
    }});

    suite.cases.push_back({"identity throws on zero dimension", [] {
        axion::Matrix m;
        ASSERT_THROWS(m.identity(0), axion::InvalidShapeError);
    }});

    suite.cases.push_back({"identity throws on negative dimension", [] {
        axion::Matrix m;
        ASSERT_THROWS(m.identity(-1), axion::InvalidShapeError);
    }});

    run_suite(suite);
    return test_summary();
}
