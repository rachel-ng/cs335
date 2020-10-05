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
    
    void resize(size_t new_size);

    T& at(int row, int col);

    size_t size() const;
    void print() const;
};


// default constructor 
template <typename T>
SquareMatrix<T>::SquareMatrix(): _size(0), _arry(nullptr){ }

template <typename T>
SquareMatrix<T>::SquareMatrix(size_t SIZE): _size(SIZE) {
    if (SIZE < 0) {
        throw std::invalid_argument("invalid size");
    }

    _arry = new T*[SIZE];
    for (int r = 0; r < SIZE; r++) {
        _arry[r] = new T[SIZE];
    }
}

// big 5 copy constructor 
template <typename T>
SquareMatrix<T>::SquareMatrix(const SquareMatrix& target): _size(target._size) {
    _arry = new T*[_size];
    for (int r = 0; r < _size; r++) {
        _arry[r] = new T[_size];
        for (int c = 0; c < _size; c++) { 
            _arry[r][c] = target._arry[r][c];
        }
    }
}

// big 5 move constructor 
template <typename T>
SquareMatrix<T>::SquareMatrix(SquareMatrix&& target): _size(target._size), _arry(target._arry) {
    target._arry = nullptr;
}

template <typename T>
void SquareMatrix<T>::clear() {
    if (_arry != nullptr) {
        for (int i = 0; i < _size; i++) {
            delete[] _arry[i];
        }
        delete[] _arry;
        _arry = nullptr;
    }
}

// big 5 destructor 
template <typename T>
SquareMatrix<T>::~SquareMatrix() {
    clear();
}

// big 5 copy operator 
template <typename T>
SquareMatrix<T>& SquareMatrix<T>::operator=(const SquareMatrix& rhs) {
    if (this == &rhs) {
        return *this;
    }

    if (_arry != nullptr) {
        clear();
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

// big 5 move operator  
template <typename T>
SquareMatrix<T>& SquareMatrix<T>::operator=(SquareMatrix&& rhs) {
    if (this == &rhs) {
        return *this;
    }

    if (_arry != nullptr) {
        clear();
    }

    _arry = rhs._arry;
    _size = rhs._size; 

    rhs._arry = nullptr;
    rhs._size = 0;
    
    return *this;
}

// overloaded == operator 
template <typename T>
bool SquareMatrix<T>::operator==(const SquareMatrix& rhs) {
    if (_size != rhs._size) {
        return false;
    }

    for (int r = 0; r < _size; r++) {
        for (int c = 0; c < _size; c++) {
            if (_arry[r][c] != rhs._arry[r][c]) {
                return false;
            }
        }
    }

    return true;
}

// overloaded != operator 
template <typename T>
bool SquareMatrix<T>::operator!=(const SquareMatrix& rhs) {
    if (_size != rhs._size) {
        return true;
    }

    for (int r = 0; r < _size; r++) {
        for (int c = 0; c < _size; c++) {
            if (_arry[r][c] != rhs._arry[r][c]) {
                return true;
            }
        }
    }

    return false;
}

// overloaded + operator
template <typename T>
SquareMatrix<T> SquareMatrix<T>::operator+(const SquareMatrix& rhs) {
    if (_size != rhs._size) {
        throw std::invalid_argument("matrices are not the same size");
    }

    SquareMatrix<T> out(_size);
    for (int r = 0; r < _size; r++) {
        for (int c = 0; c < _size; c++) { 
            out._arry[r][c] = _arry[r][c] + rhs._arry[r][c];
        }
    }

    return out;
}

template <typename T>
void SquareMatrix<T>::resize(size_t new_size) {
    clear();

    _size = new_size;

    if (new_size == 0) { // strange but alright
        return;
    }

    _arry = new T*[new_size];
    for (int r = 0; r < new_size; r++) {
        _arry[r] = new T[new_size];
    }
}

template <typename T>
T& SquareMatrix<T>::at(int row, int col) {
    if (row < _size && row > -1 && col < _size && col > -1) {
        return _arry[row][col];
    }

    throw std::out_of_range("invalid row and / or column");  
}

template <typename T>
size_t SquareMatrix<T>::size() const {
    return _size;
}

template <typename T>
void SquareMatrix<T>::print () const {
    for (int r = 0; r < _size; r++) {
        for (int c = 0; c < _size; c++) {
            std::cout << _arry[r][c] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}




