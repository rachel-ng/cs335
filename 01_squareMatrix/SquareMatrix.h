#pragma once

template <typename T>
class SquareMatrix{
private: 
    T** _arry;
    size_t _size;

    void clear ();

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
    SquareMatrix<T> operator+(const SquareMatrix& rhs);
    
    T& at(int row, int col);
    void resize(size_t new_size);

    size_t size() const;
    void print() const;
};

#include "SquareMatrix.hxx"

