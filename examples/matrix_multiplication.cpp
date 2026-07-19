#include <iostream>
#include <vector>
#include <axion/matrix.hpp>

int main() {
    
    axion::Matrix A({
        {1 ,3 ,5},
        {7, 9, 11},
        {13, 15, 17}
    });
    axion::Matrix B({
        {2, 4, 6},
        {8, 10, 12},
        {14, 16, 18}
    });

    axion::Matrix Prod = A * B;

    std::cout << Prod;

    return 0;
}