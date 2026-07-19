#include <iostream>
#include <vector>
#include <axion/matrix.hpp>

int main() {
    std::cout << axion::VERSION << "\n";

    axion::Matrix A({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    });
    
    axion::Matrix Res = A + A;

    axion::Matrix I;
    I.identity(3);

    if(A==Res) {
        std::cout << "Both matrices are equal";
    }
    else {
        std::cout << Res << "\n";
        std::cout << I;
    }

    std::cout << "Rows = " << A.rows_() << "\n";
    std::cout << "Cols = " << A.cols_();

    return 0;
}