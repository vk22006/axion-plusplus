#include <iostream>
#include <vector>
#include <axion/matrix.hpp>

int main() {

    axion::Matrix A({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    });

    axion::Matrix T = A.transpose();
    std::cout << T;

    std::cout << "Rows = " << A.rows_() << "\n";
    std::cout << "Cols = " << A.cols_();

    return 0;
}