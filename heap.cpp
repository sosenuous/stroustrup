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

Heap::~Heap() {
  if (left) delete left; 
  if (right) delete right;
}

  virtual int &operator[](int i) const; 

  void add(int ); // adds a new element
  void pop() ;    // removes the top element
