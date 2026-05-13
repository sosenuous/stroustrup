#ifndef __STRUCTURES__
#define __STRUCTURES__

template <typename T> 
class Container {
  int size;
public:

  Container(int s) : size(s) {}
 
  virtual int length() const { return size; }; 
  virtual T &operator[](int i) const = 0; 
  virtual ~Container() {};
};


template <typename T> 
class Vector : public Container<T> {

  T* data; 

public:

  Vector() : Container<T>(0) { std :: cout << Container<T>::length(); }
  Vector(int n, T z) ;
  Vector(int n , const T  a[] )  ;
  
  // copy constructor 
  Vector(const Vector & rhs) : Container<T>(rhs) {
    data = new T[Container<T>::length()]; 

    for (int i = 0; i < Container<T>::length(); i++)
      data[i] = rhs.data[i]; 
  }

  Vector(std::initializer_list<T> list) : Container<T>(list.size()) {
    data = new T[Container<T>::length()]; 
    T* ptr = data; 
    for (T val : list) {
      *ptr++ = val;
    } 
  }


// int size() { return size * size;}


  // assignment operator 
  inline Vector<T> & operator =(const Vector<T> &rhs) {
    Container<T>::operator=(rhs);

    if (data) delete [] data;
    data = new T[Container<T>::length()]; 

    for (int i = 0; i < Container<T>::length(); i++)
      data[i] = rhs.data[i]; 

    std::cout<<"operator=";

    return *this;
  }
  


  ~Vector();

  // move constructor
  Vector(Vector<T> && rhs) : Container<T>(rhs) {
    data = rhs.data; 
   
    rhs.data = nullptr;
    rhs.size = 0;
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
    if (i >=0 && i < Container<T>::length())
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

  int length() const override { return Vector<T>::length() + 10;  }

};

#endif