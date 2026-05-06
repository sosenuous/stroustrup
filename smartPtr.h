#ifndef __SMARTPTR_H__
#define __SMARTPTR_H__

template <typename T> 
class smart_ptr {

  T  * ptr  ;

  public:
  smart_ptr(T *p) : ptr(p) {}
  ~smart_ptr() { if (ptr) delete ptr; }
    
  T operator*() const { return *ptr; }
  T &operator[]  (int i)  { return ptr[i]; }  
}  ;




#endif