#include "SquareMatrix.h"

template <typename T>
SquareMatrix<T>::SquareMatrix(): _size(0), _arry(nullptr){ }


template <typename T>
SquareMatrix<T>::SquareMatrix(size_t SIZE) {
    _size = SIZE;
    _arry = new T*[_size];
    for (int i = 0; i < _size; i++) {
        _arry[i] = new T[_size];
        for (int j = 0; j < _size; j++) { 
            _arry[i][j] = 0;
        }
    }
}

template <typename T>
SquareMatrix<T>::~SquareMatrix() {
    for (int i = 0; i < _size; i++) {
        delete[] _arry[i];
    }
    delete[] _arry;
}

template <typename T>
SquareMatrix<T>& SquareMatrix<T>::operator=(const SquareMatrix& rhs) {
    if (this == &rhs) {
        return *this;
    }
    if (_arry != nullptr) {
        for (int i = 0; i < _size; i++) {
            delete[] _arry[i];
        }
        delete[] _arry;
    }

    int new_size = rhs._size;
    _arry = new T*[new_size];
    for (int r = 0; r < new_size; r++) {
        _arry[r] = new T[new_size];
        for (int c = 0; c < new_size; c++) { 
            _arry[r][c] = rhs._arry[r][c];
        }
    }
    _size = new_size;

    return *this;
}

template <typename T>
SquareMatrix<T>& SquareMatrix<T>::operator=(const SquareMatrix&& rhs) {
    if (_arry != nullptr) {
        for (int i = 0; i < _size; i++) {
            delete[] _arry[i];
        }
        delete[] _arry;
    }

    _arry = rhs._arry;
    _size = rhs._size; 

    rhs._arry = nullptr;
    
    return *this;
}

template <typename T>
bool SquareMatrix<T>::operator==(const SquareMatrix& rhs) {
    for (int r = 0; r < _size; r++) {
        for (int c = 0; c < _size; c++) {
            if (this->_arry[r][c] != rhs._arry[r][c]) {
                return false;
            }
        }
    }
    return true;
}


template <typename T>
T& SquareMatrix<T>::at(int row, int col) {
    if (row < _size && row > -1 && col < _size && col > -1) {
        return _arry[row][col];
    }
    throw std::out_of_range("unable to retrieve items at specified row and column");  
}


template <typename T>
void SquareMatrix<T>::clear() {
    for (int i = 0; i < _size; i++) {
        delete[] _arry[i];
    }
    
    delete[] _arry;

    _arry = nullptr;
}

template <typename T>
void SquareMatrix<T>::make(const size_t SIZE) {
    if (_arry != nullptr) {
        clear();
    }
    _arry = new T*[new_size];
    for (int r = 0; r < new_size; r++) {
        _arry[r] = new T[new_size];
        for (int c = 0; c < new_size; c++) { 
            _arry[r][c] = 0;
        }
    }

    _size = new_size;
}


template <typename T>
size_t SquareMatrix<T>::size() {
    return _size;
}

template <typename T>
void SquareMatrix<T>::resize(const size_t new_size) {
    clear();
    make(new_size);
}

template <typename T>
void SquareMatrix<T>::print () {
    for (int r = 0; r < _size; r++) {
        for (int c = 0; c < _size; c++) {
            std::cout << _arry[r][c] << " ";
        }
        std::cout << std::endl;
    }
}


