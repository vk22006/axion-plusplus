// MatrixConstruction.cpp — tests for all three Matrix constructors

#include "test_utils.hpp"
#include "axion/matrix.hpp"
#include "axion/exceptions.hpp"

int main() {
    TestSuite suite{"MatrixConstruction"};

    // ── default constructor ──────────────────────────────────────────────
    suite.cases.push_back({"default ctor produces 0x0 matrix", [] {
        axion::Matrix m;
        ASSERT_EQ(m.rows_(), 0u);
        ASSERT_EQ(m.cols_(), 0u);
    }});

    // ── size constructor ─────────────────────────────────────────────────
    suite.cases.push_back({"size ctor sets correct dimensions", [] {
        axion::Matrix m(3, 4);
        ASSERT_EQ(m.rows_(), 3u);
        ASSERT_EQ(m.cols_(), 4u);
    }});

    suite.cases.push_back({"size ctor initialises elements to zero", [] {
        axion::Matrix m(2, 2);
        ASSERT_DOUBLE_EQ(m(0, 0), 0.0);
        ASSERT_DOUBLE_EQ(m(0, 1), 0.0);
        ASSERT_DOUBLE_EQ(m(1, 0), 0.0);
        ASSERT_DOUBLE_EQ(m(1, 1), 0.0);
    }});

    // ── vector-of-vectors constructor ────────────────────────────────────
    suite.cases.push_back({"vector ctor stores values correctly", [] {
        axion::matrix raw = {{1, 2, 3}, {4, 5, 6}};
        axion::Matrix m(raw);
        ASSERT_EQ(m.rows_(), 2u);
        ASSERT_EQ(m.cols_(), 3u);
        ASSERT_DOUBLE_EQ(m(0, 0), 1.0);
        ASSERT_DOUBLE_EQ(m(1, 2), 6.0);
    }});

    suite.cases.push_back({"vector ctor throws on empty outer vector", [] {
        axion::matrix raw = {};
        ASSERT_THROWS(axion::Matrix(raw), axion::InvalidShapeError);
    }});

    suite.cases.push_back({"vector ctor throws on empty inner vector", [] {
        axion::matrix raw = {{}};
        ASSERT_THROWS(axion::Matrix(raw), axion::InvalidShapeError);
    }});

    suite.cases.push_back({"vector ctor throws on ragged rows", [] {
        axion::matrix raw = {{1, 2}, {3}};
        ASSERT_THROWS(axion::Matrix(raw), axion::InvalidShapeError);
    }});

    run_suite(suite);
    return test_summary();
}
