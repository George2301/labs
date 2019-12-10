#include <cstdio>
#include <conio.h>
#include "class.h"

using namespace std;


int main(int argc, char *argv[]){
  
  int n, m;
  //scanf("%d %d", &n, &m);
  cin >> n >> m;
  Matrix ma(n, m);
  ma.MatrixInput();
  ma.MatrixOutput();
  double a = ma.MAtrixAverage();
  //printf("Average: %6.2f\n", a);
  //printf("\n");
  cout << "Average: " << a << endl << endl;

  Matrix m2;
  ma.MatrixBiggerElements(m2, 2);
  m2.MatrixOutput();
  //printf("\n");
  cout << std::endl;

  Matrix m3;
  ma.MatrixBiggerElements(m3);
  m3.MatrixOutput();
  //printf("\n");
  cout << endl;

  Matrix m4;
  m4.MatrixFromNumber(2);
  m4.MatrixOutput();
  //printf("\n");
  cout << endl;


  cout << "Program ended, press any key to close" << endl;
  while (!kbhit()){}
  return 0;
}