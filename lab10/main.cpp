#include <cstdio>
#include <conio.h>
#include "class.h"

using namespace std;


int main(int argc, char *argv[]){
  
  int n, m;
  cin >> n >> m;
  Matrix ma(n, m);
  ma.MatrixInput();
  cout << "//ma: " << endl;
  ma.MatrixOutput();
  double a = ma.MAtrixAverage();
  cout << "//Average: " << a << endl << endl;

  Matrix m2;
  ma.MatrixBiggerElements(m2, 2);
  cout << "//m2 = ma + 2: " << endl;
  m2.MatrixOutput();
  cout << endl;

  Matrix m3;
  ma.MatrixBiggerElements(m3);
  cout << "//m3 = ma: " << endl;
  m3.MatrixOutput();
  cout << endl;

  Matrix m4;
  m4.MatrixFromNumber(2);
  cout << "//m4 = 2: " << endl;
  m4.MatrixOutput();
  cout << endl;

  bool f = ma == m2;
  cout << "//m2 == ma ? " << endl;
  cout << f << endl;
  cout << "//m3 == ma ? " << endl;
  cout << (ma == m3) << endl;

  cout << endl;
  ma[1][0] = 10;
  cout << "//ma[1][0] = 10 " << endl;
  ma.MatrixOutput();
  cout << endl;

  Matrix m5;
  cout << endl;
  cout << "//m5 = ma: " << endl;
  m5 = ma;
  m5.MatrixOutput();
  cout << endl;

  cout << endl;
  cout << "//m5 = m2 + ma: " << endl;
  m5 = m2 + ma;
  m5.MatrixOutput();
  cout << endl;

  Matrix m6;
  cout << endl;
  cout << "//m6 = m2 + ma: " << endl;
  m6 = MatrixSum(m2, ma);
  m6.MatrixOutput();
  cout << endl;

  cout << endl;
  cout << "//m6 = m2 - ma: " << endl;
  m6 = MatrixDiffer(m2, ma);
  m6.MatrixOutput();
  cout << endl;

  cout << "Program ended, press any key to close" << endl;
  while (!kbhit()){}
  return 0;
}