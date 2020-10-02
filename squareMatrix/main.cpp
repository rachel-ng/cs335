#include <iostream>
#include <stdexcept>
#include "SquareMatrix.h"

int main() {
    SquareMatrix<int> s(10);
    SquareMatrix<int> b(10);
    std::cout << (s == b ? "match" : "no match") << std::endl;
    s.at(2,1) = 100;
    s.print(); 
    std::cout << std::endl;
    if (s == b) { 
        std::cout << "match" << std::endl;
    }
    else {
        std::cout << "no match" << std::endl;
    }
    b = s; 
    s.print(); 
    std::cout << std::endl;
    b.print(); 
    std::cout << std::endl;
    std::cout << (s == b ? "match" : "no match") << std::endl;
    std::cout << std::endl;
    s.resize(5); 
    std::cout << std::endl;
    s.print(); 
    std::cout << std::endl;
    s.at(2,1) = 12341234;
    s.print(); 
    std::cout << s.at(2,1) << std::endl;
    std::cout << s.at(3,1) << std::endl;
    std::cout << s.at(5,1) << std::endl;
    std::cout << s.at(6,1) << std::endl;
    s.resize(6); 
    s.print(); 
    return 0;
}

