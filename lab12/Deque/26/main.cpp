#include <cstdio>
#include <list>
#include <fstream>
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
  d.SeparateVowels(v, n);
  cout << "Only vowels: " << endl;
  cout << v << endl;
  cout << "Everything else: " << endl;
  cout << n << endl;

  system("pause");
  return 0;
}