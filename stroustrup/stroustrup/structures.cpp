#include <iostream>


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




class Vector {

  int len;
  int * data;

  public:
  Vector(int n) : len(n), data (new int[n]) { 
    for (int i = 0; i < len; i++) data[i] = 0; 
  }

  Vector(int n , const int  a[] ) : len (n), data(new int[n]) 
  { 
    for (auto i = 0; i < n; ++i) data[i] = a[i];
  }


  ~Vector() {
    delete [] data;
  }

  int &operator[](int i) {
    return data[i];
  }

  int length() { return len; }


  protected:
 
 
};

/* 
[ ][ ]  --->   [ ][ ][ ][ ][ ][ ][ ] 


*/



using namespace std;


 



int main() 
{
  auto x = 1;
  auto y = 0;

  Vector v(5); 
  v[0] = 42;  // v.operator[](0) = 42;
  cout << v[0]; // v.operator[](0);

  swap(x, y);

  cout << " x == " << x << " , y == " << y << "\n";

  int a[]= {1,2,3,4,5};
  Vector w(5, a);
  for (auto i = 0 ; i< 5; ++i) cout << w[i] << "," ;
  cout << "\n";

  

  return 0;
} ///  v.~Vector() ; w.~Vector();
