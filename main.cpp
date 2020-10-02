#include <iostream>
#include <stdexcept>
#include "SquareMatrix.h"

int main() {
    SquareMatrix<std::string> s(10);
    s.at(2,1) = "hi";
    s.print(); 
    std::cout << std::endl;
    s.resize(5); 
    std::cout << std::endl;
    s.print(); 
    std::cout << std::endl;
    s.at(2,1) = "hello";
    s.print(); 
    std::cout << s.at(2,1) << std::endl;
    std::cout << s.at(3,1) << std::endl;
    s.resize(6); 
    s.print(); 
    return 0;
}

