#include <iostream>


struct Vector {
  double* elem; // pointer to elements
  int sz;       // number of elements
};

Vector v;

void vector_init(Vector &v , int s) // initialize a Vector
{ 
  v.elem = new double[s];
  v.sz = s;
}

using namespace std;

void print(int v[] , int s) {
  for (auto i = 0 ; i < s ; i++) 
  {
    cout << v[i] << "\n";
  }
}

// excercise :  the following
// void print(int *v , int s) ..
// void print(int v[], int s) ..
// void print(int )


void print()
{
  int v1[10] = { 0,1,2,3,4,5,6,7,8,9};

  print(v1,10);

}
void print(const vector<int> & p){

  for (auto c : p) {
    cout << c << ',';
  }
  cout << '\n';

}



int main() 
{
  print();
  int v[] = {1,2,3,4,3,2,1};
  print(v, 7);
  
  // zero terminated strings
  
  for (const char *p = "Hello World!"; *p ; p++) {
    cout << *p ;
  }
  cout << '\n';

  string hello = "Hello, Universe!"; 
  cout << hello << '\n';


  constexpr auto pi  = (float)3141593 / 1000000;
  cout << pi << '\n' ;


  print(vector<int>({1,2,4,5,7,8,24}));

  char *p = 0;
  

  return 0;
}
