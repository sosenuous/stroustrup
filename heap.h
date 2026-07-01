#ifndef __HEAP_H__
#define __HEAP_H__

#include "structures.h"

template <typename T>
class Heap : public Container<T> {

  T data;
  Heap<T>* left;
  Heap<T>* right; 

public:
  Heap() : Container<T>(0), left(nullptr), right(nullptr) {}
  Heap(T d) : Container<T>(1), data(d), left(nullptr), right(nullptr) {}
  virtual ~Heap();

  virtual T &operator[](int i) const; 

  void add(T); // adds a new element
  void pop() ;    // removes the top element
  T peek() const {
    return data;
  }

private:

  
void add_to_children(T value) ;

};






#endif