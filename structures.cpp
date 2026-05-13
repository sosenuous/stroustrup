#include <iostream>
#include "structures.h"
#include <assert.h>




// implement operator+ that adds two vectors component-wise 
// c = a + b ; // where a and b are Vectors
template <typename T>
Vector<T> operator+(const Vector<T> &a , const Vector<T> &b);

template <typename T>
Vector<T>::Vector(int n, T z) : Container<T>(n), data (new int[n]) { 
    assert(n >= 0);
    for (int i = 0; i < Container<T>::length(); i++) data[i] = z; 
}

template <typename T>
Vector<T>::Vector(int n , const T  a[] ) : Container<T>(n) , data(new int[n]) 
  { 
    for (auto i = 0; i < n; ++i) data[i] = a[i];
  }

template <typename T>
Vector<T>::~Vector() {
    std::cout << "~Vector";
    if (data) delete [] data;
  }

  // implement operator+ that adds two vectors component-wise 
  // c = a + b ; // where a and b are Vectors
template <typename T>
Vector<T> operator+(const Vector<T> &a , const Vector<T> &b) { 
    if (a.length() != b.length()) { 
        throw std::length_error("vector should obvs be the same length duh");
    }
    
    Vector<T> result(a.length()); 
    
    for (int i = 0; i < a.length(); i++) { 
      result[i] = a[i] + b[i]; 
    }
    
    return result; 
   }

/*
Vector::Vector(std::initializer_list<int> lst) : len(lst.size()), data(new int [lst.size()])


  {
    std::copy(lst.begin(), lst.end(), data);
  }


*/