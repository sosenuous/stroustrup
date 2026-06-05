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
  if (this->size()==0) throw std::out_of_range("Heap::pop");
  else
  if (!left) { 
    data = right-> data; 
    right-> pop();
  } else if (!right) { 
    data = left->data; 
    left->pop();
  } else // both left and right != nullptr
  if (left->peek() < right->peek()) {
    data = left-> peek();
    left->pop();
  } else {
    data = right->peek();
    right->pop();
  }
}    

template <typename T>
T &Heap<T>::operator[](int i) const
{

}
