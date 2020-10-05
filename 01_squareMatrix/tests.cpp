#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "SquareMatrix.h"

SquareMatrix<int> s(10);
SquareMatrix<int> m(10);
SquareMatrix<int> a;

TEST_CASE("resize"){
    CHECK(s.size() == 10);
    CHECK(m.size() == 10);
    CHECK(a.size() == 0);

    s.print();
    m.print();
    a.print();
}

TEST_CASE("== / !="){
    bool c = s == m;
    CHECK(c);
    c = s != m;
    CHECK(!c);
}

TEST_CASE("resize"){
    std::cout << "\ntesting resize\n" << std::endl;

    s.at(0,0) = 666;

    s.resize(5);

    CHECK(s.at(0,0) != 666);

    CHECK(s.size() == 5);
    bool c = s == m;
    CHECK(!c);
    c = s != m;
    CHECK(c);

    m.resize(5);
    c = s == m;
    CHECK(c);
    c = s != m;
    CHECK(!c);
}

TEST_CASE("at(r,c)"){
    std::cout << "\ntesting at(r,c)\n" << std::endl;

    s.at(1,3) = 5;
    s.at(2,1) = 100;
    s.at(3,4) = 87;
    
    s.print();
    m.print();
    a.print();

    bool c = s == m;
    CHECK(!c);

    bool errCaught = false;
    try {
        s.at(6,1) = 100;
    } catch (const std::out_of_range& e) {
        std::cout << "at(6,1) out of range" << std::endl;
        errCaught = true;
    }
    CHECK(errCaught);

    errCaught = false;
    try {
        s.at(5,1) = 100;
    } catch (const std::out_of_range& e) {
        std::cout << "at(5,1) out of range" << std::endl;
        errCaught = true;
    }
    CHECK(errCaught);

    errCaught = false;
    try {
        s.at(-1,-1) = 100;
    } catch (const std::out_of_range& e) {
        std::cout << "at(-1,-1) out of range" << std::endl;
        errCaught = true;
    }
    CHECK(errCaught);
}

TEST_CASE("big 5"){
    std::cout << "\ntesting big 5\n" << std::endl;
    // copy operator 
    a = s;
    a.print();
    s.print();

    bool c = a == s;
    CHECK(c);

    // copy constructor  
    SquareMatrix<int> b = a;
    a.print();
    b.print();

    c = a == b;
    CHECK(c);

    // move operator 

    // move constructor 

}








/*
TEST_CASE(""){
    CHECK();
}

TEST_CASE(""){
    bool errCaught = false;
    try {

    } catch (const std::exception& e) {
        errCaught = true;
    }
    CHECK(errCaught);
}
*/
