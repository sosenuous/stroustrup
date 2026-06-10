#ifndef __STRUCTURES__
#define __STRUCTURES__

#include <iostream>

template <typename T> 
class Container {
protected:
  int s;
public:

  Container(int ss) : s(ss) {}
 
  virtual int size() const { return s; }; 
  virtual T &operator[](int i) const = 0; 
  virtual ~Container() {};
};


template <typename T> 
class Vector : public Container<T> {

  T* data; 

public:

  Vector() : Container<T>(0) { std :: cout << Container<T>::size(); }
  Vector(int n, T z) ;
  Vector(int n , const T  a[] )  ;
  
  // copy constructor 
  Vector(const Vector & rhs) : Container<T>(rhs) {
    data = new T[Container<T>::size()]; 

    for (int i = 0; i < Container<T>::size(); i++)
      data[i] = rhs.data[i]; 
  }

  Vector(std::initializer_list<T> list) : Container<T>(list.size()) {
    data = new T[Container<T>::size()]; 
    T* ptr = data; 
    for (T val : list) {
      *ptr++ = val;
    } 
  }


  // assignment operator 
  inline Vector<T> & operator =(const Vector<T> &rhs) {
    Container<T>::operator=(rhs);

    if (data) delete [] data;
    data = new T[Container<T>::size()]; 

    for (int i = 0; i < Container<T>::size(); i++)
      data[i] = rhs.data[i]; 

    std::cout<<"operator=";

    return *this;
  }
  


  ~Vector();

  // move constructor
  Vector(Vector<T> && rhs) : Container<T>(rhs) {
    data = rhs.data; 
   
    rhs.data = nullptr;
    rhs.s = 0;
  }

  // move assignment
  Vector<T> & operator=(Vector<T> && rhs) {
    Container<T>::operator=(rhs);
    
    if (this != &rhs) { 
      if (data) delete[] data; 

      data = rhs.data; 
      rhs.data = 0;
    }
    return *this;
  }

  // indexing
  T &operator[](int i) const override {
    if (i >=0 && i < Container<T>::size())
      return data[i];
    else throw std::out_of_range("Vector::operator[]");
  }
      

 
};


  // implement operator+ that adds two vectors component-wise 
  // c = a + b ; // where a and b are Vectors
template <typename T>
Vector<T> operator+(const Vector<T> &a , const Vector<T> &b); 


template <typename T>
class SuperVector : public Vector<T>{
public:
  SuperVector() : Vector<T>() {}

  int size() const override { return Vector<T>::size() + 10;  }

};


#include "structures.cpp"

#endif