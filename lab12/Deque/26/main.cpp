#include <cstdio>
#include <list>
#include <fstream>
#include "deque_add.h"

using namespace std;



int main(int argc, char *argv[]){
  Deque_Exp d, v, n;
  
  Read(d, argv[1]);
  cout << "Deque: " << endl;
  cout << d << endl;
  SeparateVowels(d, v, n);
  cout << "Only vowels: " << endl;
  cout << v << endl;
  cout << "Everything else: " << endl;
  cout << n << endl;

  system("pause");
  return 0;
}