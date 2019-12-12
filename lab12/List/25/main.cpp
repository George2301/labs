#include <cstdio>
#include <cstdlib>
#include "node_add.h"

using namespace std;

int main(int argc, char *argv[]){
  List_Exp l;
  int a, b;
  ifstream in;

  in.open(argv[1]);
  in >> a >> b;
  in >> l;
  in.close();

  cout << l << endl;

  if (l.CheckInRange(a, b))
    l.DeleteEven();
  cout << l << endl;

  system("pause");
  return 0;
}