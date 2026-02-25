#include <iostream>










void print(int a[], int size)
{

  for (int i = 0 ; i < size ; i++) {
    std::cout << a[i] << '\n';
  }


  // print them to cou 
}

retretret

void swap(int *x , int *y)
{
  int z = * y;
  *y = *x; 
  *x = z;

  x ++;
  *y = x [108];
}

void swap2(const int &x , const int &y) {
  int z = x;
  x= y;
  y = z;

}




using namespace std;

int main() 
{
  // define an array of 10 integers
  int v[] = {1,2,3,4,5,6,8,9,10};


  print( v , 10);

  int a = 1, b = 10;
  cout << "a == " << a <<", b == " << b << '\n';
  swap(&a, &b);
  cout << "a == " << a <<", b == " << b << '\n';
  swap2(a,b);

  cout << "a == " << a <<", b == " << b << '\n';


  // ( a == 10 && b = 1);


  return 0;
}
