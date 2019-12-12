#include <cstdio>
#include "deque_add.h"

using namespace std;

int main(int argc, char *argv[]){
  Deque_Exp d, v, n;
  ifstream in;

  in.open(argv[1]);
  in >> d;
  in.close();

  cout << "Deque: " << endl;
  cout << d << endl;
  d.SeparateNumbers(v, n);
  cout << "Multiple 8: " << endl;
  cout << v << endl;
  cout << "Everything else: " << endl;
  cout << n << endl;

  system("pause");
  return 0;
}