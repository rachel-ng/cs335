#pragma once

template<typename T>
class myVector
{
private:
   T* _ptr;
   size_t _size;
   size_t _capacity;

public:
   myVector();

   // Big Five
   ~myVector();
   myVector(const myVector& trg);
   myVector(myVector&& trg);
   myVector& operator=(const myVector& rhs);
   myVector& operator=(myVector&& rhs);

   void push_back(const T & element);
   void pop_front();
   bool empty() const;
   size_t size() const;
   size_t capacity() const;
   T& operator[](size_t index);
   T& at(size_t index);
   void reserve(size_t amount);
   void resize(size_t num_of_elems, T element = T());

private:
   void reallocate(size_t new_capacity);

};

#include "myVector.cpp"
