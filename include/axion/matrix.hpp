#pragma once

namespace axion {

class Matrix {
    private:
        std::vector<std::vector<double>> M;
        size_t rows;
        size_t cols;
    public:
        Matrix(size_t rows, size_t cols);
        Matrix(const std::vector<std::vector<double>>& M);
        std::vector<std::vector<double>> add(const std::vector<std::vector<double>>& mat_A, const std::vector<std::vector<double>>& mat_B);
        std::vector<std::vector<double>> subtract(const std::vector<std::vector<double>>& mat_A, const std::vector<std::vector<double>>& mat_B);
        std::vector<std::vector<double>> transposeOf(const std::vector<std::vector<double>>& mat_A);

        size_t rowCount();
        size_t colCount();

        void input(std::vector<std::vector<double>>& mat);
        void display(const std::vector<std::vector<double>>& mat);
};

} //namespace axion