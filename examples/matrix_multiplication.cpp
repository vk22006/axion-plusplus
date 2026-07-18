#include <iostream>
#include <vector>
#include <axion/matrix.hpp>

int main() {

    axion::matrix a = {
        {1 ,3 ,5},
        {7, 9, 11},
        {13, 15, 17}
    };
    axion::matrix b = {
        {2, 4, 6},
        {8, 10, 12},
        {14, 16, 18}
    };

    axion::Matrix A(a);
    axion::Matrix B(b);
    axion::Matrix Prod = A * B;

    std::cout << Prod;

    return 0;
}