#include <cstdio>
#include <cstdlib>
#include "node_add.h"

using namespace std;

int main(int argc, char *argv[]){
  List_Exp l;
  int a, b;

  Read(l, a, b, argv[1]);

  cout << l << endl;

  if (CheckInRange(l, a, b))
    DeleteEven(l);
  cout << l << endl;

  system("pause");
  return 0;
}