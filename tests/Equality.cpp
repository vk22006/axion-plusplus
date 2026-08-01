// Equality.cpp — tests for Matrix::operator==() and operator!=()

#include "test_utils.hpp"
#include "axion/matrix.hpp"
#include "axion/exceptions.hpp"

int main() {
    TestSuite suite{"Equality"};

    // ── operator== ───────────────────────────────────────────────────────
    suite.cases.push_back({"identical matrices are equal", [] {
        axion::Matrix a({{1, 2}, {3, 4}});
        axion::Matrix b({{1, 2}, {3, 4}});
        ASSERT_TRUE(a == b);
    }});

    suite.cases.push_back({"matrices with different values are not equal", [] {
        axion::Matrix a({{1, 2}, {3, 4}});
        axion::Matrix b({{1, 2}, {3, 5}});
        ASSERT_FALSE(a == b);
    }});

    suite.cases.push_back({"matrix equals itself", [] {
        axion::Matrix a({{7, -3}, {0, 1}});
        ASSERT_TRUE(a == a);
    }});

    suite.cases.push_back({"== throws MatrixDimensionError on different shapes", [] {
        axion::Matrix a(2, 3);
        axion::Matrix b(3, 2);
        ASSERT_THROWS(a == b, axion::MatrixDimensionError);
    }});

    // ── operator!= ───────────────────────────────────────────────────────
    suite.cases.push_back({"different matrices are != true", [] {
        axion::Matrix a({{1, 0}, {0, 1}});
        axion::Matrix b({{2, 0}, {0, 2}});
        ASSERT_TRUE(a != b);
    }});

    suite.cases.push_back({"identical matrices are != false", [] {
        axion::Matrix a({{5, 5}, {5, 5}});
        axion::Matrix b({{5, 5}, {5, 5}});
        ASSERT_FALSE(a != b);
    }});

    suite.cases.push_back({"!= throws MatrixDimensionError on different shapes", [] {
        axion::Matrix a(1, 2);
        axion::Matrix b(2, 1);
        ASSERT_THROWS(a != b, axion::MatrixDimensionError);
    }});

    // ── operator() index access ──────────────────────────────────────────
    suite.cases.push_back({"operator() returns correct element", [] {
        axion::Matrix m({{10, 20}, {30, 40}});
        ASSERT_DOUBLE_EQ(m(0, 0), 10.0);
        ASSERT_DOUBLE_EQ(m(0, 1), 20.0);
        ASSERT_DOUBLE_EQ(m(1, 0), 30.0);
        ASSERT_DOUBLE_EQ(m(1, 1), 40.0);
    }});

    suite.cases.push_back({"operator() throws InvalidIndexError on out-of-bounds row", [] {
        axion::Matrix m(2, 2);
        ASSERT_THROWS(m(5, 0), axion::InvalidIndexError);
    }});

    suite.cases.push_back({"operator() throws InvalidIndexError on out-of-bounds col", [] {
        axion::Matrix m(2, 2);
        ASSERT_THROWS(m(0, 5), axion::InvalidIndexError);
    }});

    run_suite(suite);
    return test_summary();
}
