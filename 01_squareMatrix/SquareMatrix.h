#pragma once

template <typename T>
class SquareMatrix{
private: 
    T** _arry;
    size_t _size;

    void clear ();
    void make (const size_t SIZE);

public: 

    SquareMatrix();
    SquareMatrix(size_t SIZE);

    // big 5
    ~SquareMatrix(); // destructor 
    SquareMatrix(const SquareMatrix& target); // copy constructor 
    SquareMatrix(SquareMatrix&& target); // move constructor 
    SquareMatrix& operator=(const SquareMatrix& rhs); // copy operator 
    SquareMatrix& operator=(SquareMatrix&& rhs); // move operator 
    
    bool operator==(const SquareMatrix& rhs);
    bool operator!=(const SquareMatrix& rhs);
    SquareMatrix& operator+(const SquareMatrix&& rhs);
    
    T& at(int row, int col);

    size_t size() const;
    void resize(size_t new_size);

    void print() const;
};

#include "SquareMatrix.hxx"

