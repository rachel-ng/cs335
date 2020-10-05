#include <iostream>
#include <stdexcept>
#include "SquareMatrix.h"

int main() {
    SquareMatrix<int> s(10);
    SquareMatrix<int> b(10);
    SquareMatrix<int> def;

    std::cout << "s\t" << s.size() << std::endl;
    std::cout << "b\t" << b.size() << std::endl;
    std::cout << "def\t" << def.size() << std::endl;


    std::cout << (s == b ? "match" : "no match") << "\n" << std::endl;

    for (int i = 0; i < 10; i++) {
        s.at(i,i) = 666;
    }
    std::cout << (s == b ? "match" : "no match") << "\n" << std::endl;

    b = s; 
    s.print(); 
    b.print(); 

    std::cout << (s == b ? "match" : "no match") << "\n" << std::endl;
    std::cout << (s != b ? "no match" : "match") << "\n" << std::endl;

    std::cout << "resize" << std::endl;
    s.print(); 
    s.resize(5); 
    s.print(); 
    
    for (int i = 0; i < 5; i++) {
        std::cout << s.at(i,i) << " != 666" << std::endl;
    }
    for (int i = 5; i < 10; i++) {
        try {
            s.at(i,i);
        } catch (const std::out_of_range& e) {
            std::cout << "doesn't exist anymore!!" << std::endl;
        }
    }
    
    std::cout << s.at(0,4) << std::endl;
    std::cout << s.at(3,1) << std::endl;

    std::cout << s.at(2,1) << std::endl;
    s.at(2,1) = 12341234;
    s.print(); 
    std::cout << s.at(2,1) << std::endl;


    int vals [6][2] = {{6,1},{3,5},{7,7},
                       {-1,-1},{0,-10},{-8,2}};
    for (int i = 0; i < 6; i++) {
        try {
            s.at(vals[i][0],vals[i][1]) = 666;
        } catch (const std::out_of_range& e) {
            std::cout << "haha bitch at(" << vals[i][0] << "," << vals[i][1]<< ") is invalid" << std::endl;
        }
    }

    s = s;
    s.print();

    s.at(3,4) = -1;
    s.print();

    std::cout << "copy operator" << std::endl;
    b = s;
    s.print();
    b.print();

    std::cout << "copy constructor" << std::endl;
    SquareMatrix<int> a = s;
    std::cout << (a == s ? "match" : "no match") << "\n" << std::endl;

    a.at(0,0) = 1;

    std::cout << (a != s ? "no match" : "match") << "\n" << std::endl;

    a.print();
    s.print();
    
    std::cout << "move operator" << std::endl;
    a = a + s;
    a.print();

    std::cout << "a + a + a" << std::endl;
    (a + a + a).print();

    std::cout << "move constructor" << std::endl;
    SquareMatrix<int> d = a + s;
    std::cout << "d = a + s" << std::endl;
    d.print();

    s.resize(6); 
    s.print(); 
    
    std::cout << "change d" << std::endl;
    try { 
        d = a + s;
    } catch (const std::invalid_argument& err) {
        std::cout << "invalid args" << std::endl;
    }
    
    std::cout << "a = a" << std::endl;
    a = a;

    std::cout << "a = d = s" << std::endl;
    a = d = s;
   
    a.print();
    d.print();
    s.print();

    if (a == d) {
        std::cout << "a and d are the same" << std::endl;
    }
    if (a == s) {
        std::cout << "a and s are the same" << std::endl;
    }
    if (d == s) {
        std::cout << "d and s are the same" << std::endl;
    }

    return 0;
}

