#include <cstdio>
#include <locale.h>
#include <conio.h>

const int NMAX = 10;
const int MMAX = 10;

void ArrayInput(int &n, int &m, int x[][MMAX], FILE *file); 	// Функция ввода массива из файла
void ArrayOut(int n, int m, int x[][MMAX], FILE *file, char a);   // Функция вывода массива
int Comp(int x[][MMAX], int n, int m);    // Нахождение произведения
int Aver(int x[], int m);    // Нахождение среднего арифметического
void AnsOut(int n, int x[][MMAX], int m, FILE *file); 

int main(int argc, char *argv[]){ 
  int a[NMAX][MMAX];
  int b[NMAX][MMAX];
  int ca, cb, na, nb, ma, mb;
  double aa, ab;
  FILE *file1, *file2, *file0;

  file1 = fopen(argv[1], "r"); 
  file2 = fopen(argv[2], "r");

  ArrayInput(na, ma, a, file1);
  ArrayInput(nb, mb, b, file2);

  fclose(file1);
  fclose(file2);

  file0 = fopen(argv[3], "w");

  ArrayOut(na, ma, a, file0, 'A');
  ArrayOut(nb, mb, b, file0, 'B');

  ca = Comp(a, na, ma);
  cb = Comp(b, nb, mb);
  if ((ca != 0) && (cb != 0)){
    if (ca > cb){
      fprintf(file0, "Composision of nonzero elements of matrix A is bigger; A = %d , B = %d\n", ca, cb);
      AnsOut(na, a, ma, file0);
    } else if (ca < cb){
      fprintf(file0, "Composision of nonzero elements of matrix B is bigger; A = %d , B = %d\n", ca, cb);
      AnsOut(nb, b, mb, file0);
    } else if (ca == cb)
      fprintf(file0, "Composision of nonzero elements of matrix A and matrix B are the same; A = %d , B = %d\n", ca, cb);
  }

  if ((ca != 0) && (cb == 0)){
    fprintf(file0, "Nonzero elements of matrix B were not found; Composision of nonzero elements of matrix A is bigger\n");
      AnsOut(na, a, ma, file0);
  }

  if ((ca == 0) && (cb != 0)){
    fprintf(file0, "Nonzero elements of matrix A were not found; Composision of nonzero elements of matrix B is bigger\n");
    AnsOut(nb, b, mb, file0);
  }

  if ((ca == 0) && (cb == 0)){
    fprintf(file0, "Nonzero elements of matrix A and matrix B were not found\n");
  }

  fclose(file0);
  
  printf("Program ended, press any key to close\n");
  while (!kbhit()){}
  return 0;
}

void ArrayInput(int &n, int &m, int x[][MMAX], FILE *file){
  fscanf(file, "%d %d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      fscanf(file, "%d", &x[i][j]);
    } 
  return;
  } 

void ArrayOut(int n, int m, int x[][MMAX], FILE *file, char a){ 
  fprintf(file, "Array %c:\n", a);
  fprintf(file, "Size: %dx%d\n", n, m);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      fprintf(file, "%d ", x[i][j]);
    fprintf(file, "\n");
  }
  fprintf(file, "\n");
  return;
}

int Comp(int x[][MMAX], int n, int m){ 
  bool f = false;
  int c = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (x[i][j] != 0)
      {
        c *= x[i][j];
        f = true;
      }
  if (!f)
    c = 0;
  return c;
}

int Aver(int x[], int m){ 
  int k = 0;
  double a = 0;
  for (int i = 0; i < m; i++)
    if (x[i] != 0)
    {
      a += x[i];
      k++;
    }
  if (k != 0) 
    a = a / k;
  return a;
}

void AnsOut(int n, int x[][MMAX], int m, FILE *file){
  for(int i = 0; i < n; i++)
        fprintf(file, "Average of nonzero elements of line %d: %8.4f\n", i, Aver(x[i], m));
  return;
}