#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "SquareMatrix.h"

SquareMatrix<int> s(10);
SquareMatrix<int> m(10);
SquareMatrix<int> a;
SquareMatrix<std::string> st(5);

void fill (SquareMatrix<int>& m) {
    int size = m.size();
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            m.at(r,c) = 0;
        }
    }
}

void fill (SquareMatrix<std::string>& m, std::string s) {
    int size = m.size();
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            m.at(r,c) = s;
        }
    }
}

TEST_CASE("size"){
    std::cout << "\ntesting size\n" << std::endl;

    CHECK(s.size() == 10);
    fill(s);
    s.print();

    CHECK(m.size() == 10);
    fill(m);
    m.print();
    
    CHECK(a.size() == 0);
    a.print();

    a.resize(1);
    fill(a);
    CHECK(a.size() == 1);
    a.print();

    CHECK(st.size() == 5);
    fill(st,"h");
    st.print();
}

TEST_CASE("== / !="){
    std::cout << "\ntesting == and !=\n" << std::endl;

    bool c = s == m;
    CHECK(c);

    c = s != m;
    CHECK(!c);

    c = a == m;
    CHECK(!c);

    c = a != s;
    CHECK(c);
    
    SquareMatrix<int> j;
    c = a == j;
    CHECK(!c);

    c = a != j;
    CHECK(c);

    s.print();
    m.print();

    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            s.at(r,c) = r*10 + c;
        }
    }
    
    s.print();
    m.print();

    c = s == m;
    CHECK(!c);

    c = s != m;
    CHECK(c);

    s.resize(10);
    fill(s);

    c = s == m;
    CHECK(c);

    c = s != m;
    CHECK(!c);
    
    /* 
    std::cout << "short matrix, prof" << std::endl;

    SquareMatrix<short> shm(10);
    SquareMatrix<short> sh(10);

    shm.resize(2);
    shm.print();

    sh.resize(2);
    sh.print();

    c = sh == shm;
    CHECK(c);

    shm.at(0,0)=1;
    shm.at(0,1)=1;
    shm.at(1,0)=1;
    shm.at(1,1)=1;
    sh.print();
    */
}

TEST_CASE("resize"){
    std::cout << "\ntesting resize\n" << std::endl;

    std::cout << "s.resize(5)" << std::endl;
    for (int i = 0; i < 10; i++) {
        s.at(i,i) = 666;
    }
    s.print();

    s.resize(5);
    fill(s);
    CHECK(s.size() == 5);
    s.print();

    // verify resize destroys previous contents
    for (int i = 0; i < 5; i++) {
        CHECK(s.at(i,i) != 666);
    }

    bool errCaught = false;
    for (int i = 5; i < 10; i++) {
        errCaught = false;
        try {
            s.at(i,i);
        } catch (const std::out_of_range& e) {
            errCaught = true;
        }
        CHECK(errCaught);
    }

    bool c = s != m;
    CHECK(c);

    std::cout << "m.resize(6), m.resize(5)\n" << std::endl;
    m.resize(6);
    fill(m);
    CHECK(m.size() == 6);
    c = s != m;
    CHECK(c);

    m.resize(5);
    fill(m);
    CHECK(m.size() == 5);
    c = s == m;
    s.print();
    m.print();
    std::cout << "ERROR" << std::endl;
    CHECK(c);

    // verify resize(0) works
    std::cout << "a.resize(0)" << std::endl;
    a.print();
    a.resize(0);
    CHECK(a.size() == 0);
    a.print();

    st.resize(4);
    fill(st,"H");
    CHECK(st.size() == 4);
    st.print();
}

TEST_CASE("at(r,c)"){
    std::cout << "\ntesting at(r,c)\n" << std::endl;

    // verify can retrieve
    std::cout << "populate s" << std::endl;
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            std::cout << s.at(r,c) << (c < 4 ? ", " : "");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;


    // verify can modify
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            s.at(r,c) = r*10 + c;
        }
    }

    s.print();
    m.print();

    bool c = s != m;
    CHECK(c);


    // throw exception if rol or column doesn't exist
    int vals [6][2] = {{6,1},{3,5},{7,7},
                       {-1,-1},{0,-10},{-8,2}};
    bool errCaught = false;
    for (int i = 0; i < 6; i++) {
        errCaught = false;
        try {
            s.at(vals[i][0],vals[i][1]) = 666;
        } catch (const std::out_of_range& e) {
            std::cout << "at(" << vals[i][0] << "," << vals[i][1]<< ") out of range" << std::endl;
            errCaught = true;
        }
        CHECK(errCaught);
    }
}

TEST_CASE("big 5"){
    std::cout << "\ntesting big 5\n" << std::endl;

    // copy operator 
    std::cout << "copy operator" << std::endl;
    a = s;
    a.print();
    s.print();

    bool c = a == s;
    CHECK(c);


    // copy constructor  
    std::cout << "copy constructor" << std::endl;
    SquareMatrix<int> b = a;
    a.print();
    b.print();

    c = a == b;
    CHECK(c);
    

    // move operator 
    std::cout << "move operator" << std::endl;
    b = a + s;
    b.print();

    c = b == a + s ;
    CHECK(c);


    // move constructor 
    std::cout << "move constructor" << std::endl;
    SquareMatrix<int> d = a + s;
    d.print();

    c = d == a + s ;
    CHECK(c);
}



TEST_CASE("+"){
    std::cout << "\ntesting + operator\n" << std::endl;
    
    std::cout << "(a + s).print()" << std::endl;
    (a + s).print();

    std::cout << "construct d from a + s" << std::endl;
    SquareMatrix<int> d = a + s;

    a.print();
    s.print();
    d.print();

    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            CHECK(d.at(r,c) == a.at(r,c) + s.at(r,c));
        }
    }

    bool c = d == a + s ;
    CHECK(c);

    std::cout << "d = d + a" << std::endl;
    d = d + a;
    d.print();

    std::cout << "d = d + a + s" << std::endl;
    d = d + a + s;
    d.print();

    std::cout << "(d + s).print()" << std::endl;
    (d + s).print();

    std::cout << "(a + d + s).print()" << std::endl;
    (a + d + s).print();

    m.print();
    m.resize(8);
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            m.at(r,c) = r*10 + c;
        }
    }
    m.print();
    a.print();
    
    // throw exception if matrices aren't the same size 
    bool errCaught = false;
    try {
        a + m;
    } catch (const std::invalid_argument& e) {
        std::cout << "invalid matrix given\n" << std::endl;
        errCaught = true;
    }
    CHECK(errCaught);

    m.print();
    a.print();

    SquareMatrix<std::string> ste (4);
    fill(ste,"e");
    SquareMatrix<std::string> stl (4);
    fill(stl,"l");
    SquareMatrix<std::string> sto (4);
    fill(sto,"o");
    SquareMatrix<std::string> stO (4);
    fill(stO," ");
    SquareMatrix<std::string> stW (4);
    fill(stW,"W");
    SquareMatrix<std::string> str (4);
    fill(str,"r");
    SquareMatrix<std::string> stD (4);
    fill(stD,"d");

    (st + ste + stl + stl + sto + stO + stW + sto + str + stl + stD).print();

}


TEST_CASE("mentioned"){
    std::cout << "\ntesting stuff mentioned in spec\n" << std::endl;

    std::cout << "default constructor / zero param constructor" << std::endl;

    SquareMatrix<int> b;
    std::cout << "b" << "\tsize: " << b.size() << std::endl;; 
    b.print();
    b = a + s;
    std::cout << "b" << std::endl;
    b.print();

    SquareMatrix<int> d = b + b;
    std::cout << "d" << std::endl;
    d.print();


    std::cout << "a = a" << std::endl;
    a = a;
    std::cout << "a" << std::endl;
    a.print();


    std::cout << "a = b = c" << std::endl;
    a = b = d;
    std::cout << "a" << std::endl;
    a.print();
    std::cout << "b" << std::endl;
    b.print();
    std::cout << "d" << std::endl;
    d.print();

    bool c = a == d;
    CHECK(c);
    c = a == b;
    CHECK(c);
    c = b == d;
    CHECK(c);
}



/*
    std::cout << "" << std::endl;

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

