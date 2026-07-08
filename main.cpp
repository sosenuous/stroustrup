#include <iostream>

#include "structures.h"
#include "structures.cpp"
#include "smartPtr.h"
#include "heap.h"
#include "heap.cpp"

void print(int a[], int size)
{
  for (int i = 0 ; i < size ; i++) {
    std::cout << a[i] << '\n';
  }

  // print them to cou 
}


void swap(int & x , int & y)
{
  int z = y;
  y = x; 
  x = z;
}





 


enum class Color2 { red, blue, green};

Color2 c2 = Color2::blue;

Color2 & operator++ (Color2 &c) {
  using enum Color2;

  switch (c) {
    case red :  c = blue; break; 
    case blue :  c = green; break;
    case green : c = red; break;
  }

  return c;


}



using namespace std;


enum class Job {
  Programmer, 
  Designer, 
  CEO
};

union JobData {
  int number_of_languages; // programmers
  bool hates_adobe; // designers
  bool has_yacht ; // CEO
};

struct Person {
  Job job;
  JobData jobData;


};


template <typename T, int S>
class Buffer {
  T buffer [S];

  public:


  int size() const { return S;}
};



template <typename T>
std::vector<T> heap_sort_(std::vector<T> const &v) {

  Heap<T> h;

  /// insert all elemenets of v into h

  for (std::size_t i = 0 ; i < v.size(); ++i) {
    h.add(v[i]);
  }
  /// then remove them again
  std::vector<T> result; 
  result.resize(v.size());

  for (int i = v.size() -1; i >= 0; --i) { 
    result[i] = h.peek();
    h.pop();
  }

  // they will be sorted

  return result;

}

int main() 
{
//   Buffer<Vector<int>, 20> b ;
//   cout << b.size();



//   auto x = 1;
//   auto y = 0;

//   Person p ;
//   p.job = Job::Programmer;
//   p.jobData.number_of_languages = 7;
  

//   cout << p.jobData.number_of_languages << " ";



//   Vector<int> v(5, 0); 
//   v[0] = 42;  // v.operator[](0) = 42;

//   try { 

//     std::cout << v[0]; // v.operator[](0);
//     std::cout << v[6]; // out of bounds!
//     cout << "I'm here too" ; 
//   } catch (int a) {
//       std::cout << "Caught!" << a <<"\n";
//   }
//   catch (const std::out_of_range & ex ) { 
//     cout << "Out of range ";
//   }

//   swap(x, y);

//   cout << " x == " << x << " , y == " << y << "\n";

//   int a[]= {1,2,3,4,5};
//   Vector<int> w(5, a);
//   for (auto i = 0 ; i< 5; ++i) cout << w[i] << "," ;
//   cout << "\n";

//   Vector<int> u(w);

//   //u = v;

//   enum Color {red, blue, green};

//   int i = red;

//   Color c = red;


// // 
// // w =  { int size; int  * data }
// // u =  { int == w.size ; data == w.data}


//  u = v + v; // 



// Vector v1 = { 1 , 2 , 3 ,4 , 5};
// cout << "size = " << v1.size() << "\n";
// for (auto i = 0; i < v1.size() ; i++) cout << v1[i];


//   Container<int> *pcc = new Vector<int>(20, 0);


  
  
//   SuperVector<int> sv;

//   cout << sv.size();

//   smart_ptr<int> arr(new int[200]);

//   for (auto i = 0 ; i < 200; i++) arr[i] = i;  



  // 

  std::vector<int> vv {0};
  std::vector<int> j = heap_sort_(vv);

  for (std::size_t i = 0 ; i < j.size() ; ++i) {
    std::cout << (j[i]);
  }
   

  std::vector<int> v { 5, 4, 3, 2, 1};
  std::sort(v.begin(), v.end());
  auto it = std::find(v.begin(), v.end(), 4);

  int data[10] = {0};
  for (int &d : data) {
    d = random() % 100;
  }

  class iterator_data {
    int * ptr;
    public:
      iterator_data(int * p) : ptr(p) {}
      int & operator*() { return *ptr; }
      iterator_data & operator++() { ++ptr; return *this; }
      bool operator!=(const iterator_data & other) const { return ptr != other.ptr; }
  };

  class container_for_data {
    int * ptr;
    public:
      container_for_data(int * p) : ptr(p) {}
      int & operator[](int i) { return ptr[i]; }
      int size() const { return 10; }
      iterator_data begin() { return iterator_data(ptr); }
      iterator_data end() { return iterator_data(ptr + 10); }
      
  }  data_(data);


  std::sort(data_.begin(), data_.end());

  iterator_data fourtytwo = std::find(data_.begin(), data_.end(), 42);



  if (fourtytwo != data_.end()) {
    std::cout << "It is here! " << *fourtytwo << "\n";
  } else {
    std::cout << "Not found!\n";
  }
      


  return 0;






} ///  v.~Vector() ; w.~Vector(); arr.~smart_ptr()





