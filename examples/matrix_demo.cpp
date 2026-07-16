#include <iostream>
#include <vector>
#include <axion/matrix.hpp>

int main() {
    std::cout << axion::VERSION << "\n";

    axion::matrix data = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    axion::Matrix A(data);
    
    axion::matrix res = A + A;
    axion::Matrix R(res);
    std::cout << R;

    std::cout << "Rows = " << A.rows_() << "\n";
    std::cout << "Cols = " << A.cols_();

    return 0;
}