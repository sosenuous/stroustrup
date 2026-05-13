#ifndef __HEAP_H__
#define __HEAP_H__

#include "structures.h"

class Heap : public Container {

  int data;
  Heap * left, *right ; 

public:
  Heap() : Container(0), left(nullptr), right(nullptr) {}
  Heap(int d) : Container(1) , left(nullptr), right(nullptr), data(d) {}
  virtual ~Heap();

  virtual int &operator[](int i) const; 

  void add(int ); // adds a new element
  void pop() ;    // removes the top element
  int peek() const {
    return data;
  }

private:

  void add_to_children(int data) ;

};






#endif