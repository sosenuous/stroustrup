#include <iostream>
#include <complex>

using namespace std;

double square(double x) 
{
  return x*x;
}

void print_square(double x) 
{
  cout << "the square of " << x <<  " is " << square(x) << "\n";
}

double sqrt(double);
double square(double);


double get(const vector<double>& vec, int index); // type: double(const vector<double>&,int)


double d1 = 2.3;
double d2 {2.3};
double d3 = {2.3};

complex<double> z = 1;
complex<double> z2 {d1,d2};
complex<double> z3 = {d1,d2};

int i1 = (int)7.8;         // i1 becomes 7 (surprise?)
int i2 {(int)7.8};         // error: floating-point to integer conversion




int main()
{
  print_square(1.234);
  cout << sizeof(int) << "\n";

  int i = 7;
  int j = i++;
  cout << "i == " << i << ", j == " << j << "\n";
  cout << "z == " << z << "\n";
}