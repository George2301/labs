#include <cstdio>
#include <conio.h>
#include "class.h"

using namespace std;


int main(int argc, char *argv[]){
  try{
    int n, m;
    cin >> n >> m;
    Matrix a(n, m);
    a.MatrixInput();
    cout << "//a: " << endl;
    a.MatrixOutput();

    Matrix c;
    c.MatrixFromNumber(1);
    cout << "//c: " << endl;
    c.MatrixOutput();
    cout << "//a + c: " << endl;
    Matrix d = a + c;

    } catch (Exception &e) {
    cout << "Exception occured: " << e.getError() << endl;
  }

  try{
    int n, m;
    cin >> n >> m;
    Matrix a(n, m);
    a.MatrixInput();
    cout << "//a: " << endl;
    a.MatrixOutput();

    Matrix c;
    c.MatrixFromNumber(1);
    cout << "//c: " << endl;
    c.MatrixOutput();
    cout << "//a - c: " << endl;
    Matrix d = a - c;

    } catch (Exception &e) {
    cout << "Exception occured: " << e.getError() << endl;
  }

  try{
    int n1, m1;
    cin >> n1 >> m1;
    Matrix b(n1, m1);
    b.MatrixInput();
    cout << "//b: " << endl;
    b.MatrixOutput();
  } catch (Exception &e) {
    cout << "Exception occured: " << e.getError() << endl;
  }

  try{
    Matrix a;
    a.MatrixFromNumber(1);
    cout << "//a: " << endl;
    a.MatrixOutput();
    cout << "//a[2][1] = 10: " << endl;
    a[2][1] = 10;

  } catch (Exception &e) {
    cout << "Exception occured: " << e.getError() << endl;
  }

  cout << "Program ended, press any key to close" << endl;
  while (!kbhit()){}
  return 0;
}