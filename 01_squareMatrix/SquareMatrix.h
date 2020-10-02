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
    ~SquareMatrix();
    SquareMatrix(const SquareMatrix& target);
    SquareMatrix(SquareMatrix&& target);
    SquareMatrix& operator=(const SquareMatrix& rhs);
    SquareMatrix& operator=(const SquareMatrix&& rhs);
    
    bool operator==(const SquareMatrix& rhs);
    SquareMatrix& operator+(const SquareMatrix&& rhs);
    
    T& at(int row, int col);

    size_t size();
    void resize(size_t new_size);

    void print();
};

#include "SquareMatrix.hxx"

