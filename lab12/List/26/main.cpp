#include <cstdio>
#include <cstdlib>
#include <list>
#include <fstream>
#include "node_add.h"

using namespace std;



int main(int argc, char *argv[]){
  List_Exp l;
  double a;

  Read(l, a, argv[1]);

  cout << l << endl;

  if (CheckNegative(l))
    DeleteBigger(l, a);
  cout << l << endl;

  system("pause");
  return 0;
}