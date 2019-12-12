#include <cstdio>
#include <cstdlib>
#include <list>
#include <fstream>
#include "node_add.h"

using namespace std;



int main(int argc, char *argv[]){
  List_Exp l;
  double a;
  fstream in;

  in.open(argv[1]);
  in >> a;
  in >> l;
  in.close();

  cout << l << endl;

  if (l.CheckNegative())
    l.DeleteBigger(a);
  cout << l << endl;

  system("pause");
  return 0;
}