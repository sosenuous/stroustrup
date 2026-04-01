#include <iostream>
#include "structures.h"
#include <assert.h>




// implement operator+ that adds two vectors component-wise 
// c = a + b ; // where a and b are Vectors
Vector operator+(const Vector &a , const Vector &b);

Vector::Vector(int n) : Container(n), data (new int[n]) { 
    assert(n >= 0);
    for (int i = 0; i < size; i++) data[i] = 0; 
}

Vector::Vector(int n , const int  a[] ) : Container(n) , data(new int[n]) 
  { 
    for (auto i = 0; i < n; ++i) data[i] = a[i];
  }

Vector::~Vector() {
    std::cout << "~Vector";
    if (data) delete [] data;
  }

  // implement operator+ that adds two vectors component-wise 
  // c = a + b ; // where a and b are Vectors
  Vector operator+(const Vector &a , const Vector &b) { 
    if (a.length() != b.length()) { 
        throw std::length_error("vector should obvs be the same length duh");
    }
    
    Vector result(a.length()); 
    
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