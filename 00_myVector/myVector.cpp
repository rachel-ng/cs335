#include<stdexcept>

template<typename T>
myVector<T>::myVector() : _ptr(nullptr), _size(0), _capacity(0)
{ }

template<typename T>
myVector<T>::~myVector()
{
   if (_ptr != nullptr)
      delete[] _ptr;
}

template<typename T>
myVector<T>::myVector(const myVector<T>& trg):
   _ptr(trg.ptr), _size{trg._size}, _capacity(trg._capacity)
{
   if (trg._ptr == nullptr)
      return;

   _ptr = new T[_capacity];
   for (int i{ 0 }; i < _size; i++)
      _ptr[i] = trg._ptr;
}

template<typename T>
myVector<T>::myVector(myVector<T>&& trg) 
   :_ptr(trg._ptr), _size(trg._size), _capacity(trg._capacity)
{
   trg._ptr = nullptr;
}

template<typename T>
myVector<T>& myVector<T>::operator=(const myVector<T>& rhs)
{
   if (this == &rhs) 
      return;

   if (_ptr != nullptr)
      delete[] _ptr;

   _ptr = new T[rhs._capacity];
   _size = rhs._size;
   _capacity = rhs._capacity;

   for (int i{ 0 }; i < _size; i++)
      _ptr[i] = rhs._ptr[i];

   return *this;
}

template<typename T>
myVector<T>& myVector<T>::operator=(myVector<T>&& rhs)
{
   if (_ptr != nullptr)
      delete[] _ptr;    

   _ptr = rhs._ptr;
   _size = rhs._size;
   _capacity = rhs._capacity;

   rhs._ptr = nullptr;

   return *this;
}

template<typename T>
void myVector<T>::push_back(const T& element)
{
   if (_ptr == nullptr)
   {
      _ptr = new T[4];
      _capacity = 4;
   }

   if (_capacity > _size)
      reallocate(_capacity * 2);

   _ptr[_size] = element;
   _size++;
}

template<typename T>
void myVector<T>::pop_front()
{
   for (int i{ 0 }; i < _size - 1; i++)
      _ptr[i] = std::move( _ptr[i + 1] );

   _ptr[_size-1].~T();
   _size--;
}

template<typename T>
bool myVector<T>::empty() const
{
   return _size == 0;
}

template<typename T>
size_t myVector<T>::size() const
{
   return _size;
}

template<typename T>
size_t myVector<T>::capacity() const
{
   return _capacity;
}

template<typename T>
T& myVector<T>::operator[](size_t index)
{
   return _ptr[index];
}

template<typename T>
T& myVector<T>::at(size_t index)
{
   if (index < _size)
      return _ptr[index];
   else
      throw std::out_of_range("index is out of the vector range");
}

template<typename T>
void myVector<T>::reserve(size_t amount)
{
   if (_capacity >= amount)
      return;

   reallocate(amount);
}

template<typename T>
void myVector<T>::resize(size_t num_of_elems, T element)
{
   if (num_of_elems < _size)
   {
      for (size_t i{ num_of_elems }; i < _size; i++)
         _ptr[i].~T();
   }
   else if (num_of_elems > _size)
   {
      if (num_of_elems > _capacity)
         reallocate(_capacity * 2);

      for (size_t i{ _size }; i < num_of_elems; i++)
         push_back(element);
   }
}

template<typename T>
void myVector<T>::reallocate(size_t new_capacity)
{
   if (_size > new_capacity)
      return;

   T* temp{ new T[new_capacity] };

   for (int i{ 0 }; i < _size; i++)
      temp[i] = _ptr[i];

   _capacity = new_capacity;

   if(_ptr!=nullptr)
      delete[] _ptr;
   _ptr = temp;
}


