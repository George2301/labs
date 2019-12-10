#include <cstdio>
#include <conio.h>
#include "class.h"

using namespace std;


int main(int argc, char *argv[]){
  
  int n, m;
  cin >> n >> m;
  Matrix ma(n, m);
  ma.MatrixInput();
  ma.MatrixOutput();
  double a = ma.MAtrixAverage();
  cout << "Average: " << a << endl << endl;

  Matrix m2;
  ma.MatrixBiggerElements(m2, 2);
  m2.MatrixOutput();
  cout << std::endl;

  Matrix m3;
  ma.MatrixBiggerElements(m3);
  m3.MatrixOutput();
  cout << endl;

  Matrix m4;
  m4.MatrixFromNumber(2);
  m4.MatrixOutput();
  cout << endl;

  bool f = ma == m2;
  cout << f << endl;
  cout << (ma == m3) << endl;

  ma[0][0] = 10;

  cout << endl;
  ma.MatrixOutput();
  cout << endl;

  cout << endl;
  Matrix m5;
  m5 = ma + m2;
  m5.MatrixOutput();
  cout << endl;

  cout << "Program ended, press any key to close" << endl;
  while (!kbhit()){}
  return 0;
}