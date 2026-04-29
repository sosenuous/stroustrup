#ifndef __HEAP_H__
#define __HEAP_H__

#include "structures.h"

class Heap : public Container {

  int data;
  Heap * left, *right ; 

private:

  virtual int &operator[](int i) const; 
  virtual ~Heap();

  void add(int );
  int min() const;

public:
    Heap() : data(0), left(nullptr), right(nullptr) {}
    void add(int value);

};






#endif