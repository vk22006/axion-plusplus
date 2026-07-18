#include <iostream>
#include <vector>
#include <axion/matrix.hpp>

int main() {

    axion::matrix data = {
        {2, 4},
        {6, 8}
    };

    axion::Matrix A(data);

    axion::Matrix B = A / 2;

    std::cout << B;

    return 0;
}