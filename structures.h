#ifndef __STRUCTURES__
#define __STRUCTURES__

class Container {
protected:
  int size;
public:

  Container(int s) : size(s) {}
 
  virtual int length() const { return size; }; 
  virtual int &operator[](int i) const = 0; 
  virtual ~Container() {};
};


class Vector : public Container {
  int * data;

public:

  Vector() : Container(0) { std :: cout << length(); }
  Vector(int n) ;
  Vector(int n , const int  a[] )  ;
  
  // copy constructor 
  Vector(const Vector & rhs) : Container(rhs) {
    data = new int[length()]; 

    for (int i = 0; i < size; i++)
      data[i] = rhs.data[i]; 
  }

Vector(std::initializer_list<int> list) : Container(list.size()) {
  data = new int[size]; 
  int* ptr = data; 
  for (int val : list) {
    *ptr++ = val;
  }
}


// int size() { return size * size;}


  // assignment operator 
  inline Vector & operator =(const Vector &rhs) {
    Container::operator=(rhs);

    if (data) delete [] data;
    data = new int[size]; 

    for (int i = 0; i < size; i++)
      data[i] = rhs.data[i]; 

    std::cout<<"operator=";

    return *this;
  }
  


  ~Vector();

  // move constructor
  Vector(Vector && rhs) : Container(rhs) {
    data = rhs.data; 
   
    rhs.data = nullptr;
    rhs.size = 0;
  }

  // move assignment
  Vector & operator=(Vector && rhs) {
    Container::operator=(rhs);
    
    if (this != &rhs) { 
      if (data) delete[] data; 

      data = rhs.data; 
      rhs.data = 0;
    }
    return *this;
  }

  // indexing
  int &operator[](int i) const override {
    if (i >=0 && i < size)
      return data[i];
    else throw std::out_of_range("Vector::operator[]");
  }
      
  int length() const override { return size; }

 
};


  // implement operator+ that adds two vectors component-wise 
  // c = a + b ; // where a and b are Vectors
  Vector operator+(const Vector &a , const Vector &b); 


class SuperVector : public Vector {
public:
  SuperVector() : Vector() {}

  int length() const override { return Vector::length() + 10;  }

};

#endif