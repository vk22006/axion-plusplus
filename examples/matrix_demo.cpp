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
    
    axion::matrix res = A.add(data, data);
    A.display(res);

    std::cout << "Rows = " << A.rowCount() << "\n";
    std::cout << "Cols = " << A.colCount();

    return 0;
}