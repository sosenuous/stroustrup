#ifndef __HEAP_H__
#define __HEAP_H__

#include "structures.h"

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






#endif