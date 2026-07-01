#ifndef __HEAP_CPP__
#define __HEAP_CPP__

#include <stdexcept>

#include "heap.h"

/*

class Heap : public Container {

  int data;
  Heap * left, *right ; 

public:

  virtual int &operator[](int i) const; 
  virtual ~Heap();

  void add(int );
  int min() const;

  Heap() : Container(0), left(nullptr), right(nullptr) {}
  void add(int value);

private:

  void add_to_children(int data) ;

};
*/
template <typename T>
Heap<T>::~Heap() {
  delete left; 
  delete right;
}


// adds a new element
template <typename T>
void Heap<T>::add(T t ) {

  // 3 cases:
   // a)  this heap is empty
   if (this->size() == 0) {
    data = t ;
   } else if (t < data) { 
    std::swap(t, data);
    add_to_children(t) ;
   }  else add_to_children(t) ;

  this->s++;   
   // b) this heap's data > t
   // c) this heap's data <= t

} 


template <typename T>
void Heap<T>::add_to_children(T t) {
  if (!left) {
    left = new Heap(t);
  } else if (!right) {
    right = new Heap(t);
  } else if (left->size() < right->size()) left->add(t); else right->add(t);
}


// removes the top element
template <typename T>
void Heap<T>::pop() 
{
  if (this->size() == 0) throw std::out_of_range("Heap::pop");

  this->s--;

  if (!left && !right) return;          // leaf: nothing to pull up

  if (!right || (left && left->peek() < right->peek())) {
    data = left->peek();
    left->pop();
    if (left->size() == 0) { delete left; left = nullptr; }
  } else {
    data = right->peek();
    right->pop();
    if (right->size() == 0) { delete right; right = nullptr; }
  }
}

template <typename T>
T &Heap<T>::operator[](int /*i*/) const
{
  // A heap has no meaningful random-access order; indexing is not supported.
  throw std::logic_error("Heap::operator[] not implemented");
}

#endif
