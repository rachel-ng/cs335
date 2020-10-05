#include <iostream>
#include <stdexcept>
#include "SquareMatrix.h"

int main() {
    SquareMatrix<int> s(10);
    SquareMatrix<int> b(10);
    std::cout << (s == b ? "match" : "no match") << std::endl;
    s.at(2,1) = 100;
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
    std::cout << (s != b ? "match" : "no match") << std::endl;
    std::cout << std::endl;
    s.resize(5); 
    std::cout << std::endl;
    s.print(); 
    std::cout << std::endl;
    s.at(2,1) = 12341234;
    s.print(); 

    std::cout << s.at(2,1) << std::endl;
    try {
        std::cout << s.at(6,1) << std::endl;
    }
    catch (const std::out_of_range& err) {
        std::cout << "haha bitch at(6,1) is invalid" << std::endl;
    }
    std::cout << s.at(3,1) << std::endl;
    
    try {
        std::cout << s.at(5,1) << std::endl;
    }
    catch (const std::out_of_range& err) {
        std::cout << "haha bitch at(5,1) is invalid" << std::endl;
    }

    SquareMatrix<int> a = s;
    a.at(0,0) = 1;

    a.print();
    s.print();
    
    a + s;

    std::cout << "addition" << std::endl;

    SquareMatrix<int> d = a + s;
    std::cout << "made d" << std::endl;
    d.print();

    s.resize(6); 
    s.print(); 
    
    std::cout << "change d" << std::endl;
    d = a + s;
    std::cout << "change d" << std::endl;
    d.print();
    
    return 0;
}

