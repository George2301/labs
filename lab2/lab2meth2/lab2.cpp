#include <cstdio>
#include <locale.h>
#include <conio.h>

int const NMAX = 10;
int const MMAX = 10;

void ArrayInput(int &n, int &m, int x[][MMAX], FILE *file); 	// Функция ввода массива из файла
void ArrayOut(int n, int m, int x[][MMAX], FILE *file, char a);   // Функция вывода массива
void AnsOut(double a[], int n, FILE *file); // Вывод одномерного массива 
int Comp(int x[][MMAX], int n, int m);    // Нахождение произведения
void Aver(double a[], int n, int x[][MMAX], int m);    // Нахождение среднего арифметического


int main(int argc, char *argv[])
{  
  int a[NMAX][MMAX];
  int b[NMAX][MMAX];
  int ca, cb, na, nb, ma, mb;
  double aa[NMAX], ab[NMAX];
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
  if ((ca != 0) && (cb != 0))
    if (ca > cb)
    {
      fprintf(file0, "Composision of nonzero elements of matrix A is bigger; A = %d , B = %d\n", ca, cb);
        Aver(aa, na, a, ma);
        AnsOut(aa, na, file0);
    }
    else if (ca < cb)
    {
      fprintf(file0, "Composision of nonzero elements of matrix B is bigger; A = %d , B = %d\n", ca, cb);
        Aver(ab, nb, b, mb);
        AnsOut(ab, nb, file0);
    }
    else if (ca == cb)
      fprintf(file0, "Composision of nonzero elements of matrix A and matrix B are the same; A = %d , B = %d\n", ca, cb);
  
  if ((ca != 0) && (cb == 0))
  {
    fprintf(file0, "Nonzero elements of matrix B were not found; Composision of nonzero elements of matrix A is bigger\n");
        Aver(aa, na, a, ma);
        AnsOut(aa, na, file0);
  }

  if ((ca == 0) && (cb != 0))
  {
    fprintf(file0, "Nonzero elements of matrix A were not found; Composision of nonzero elements of matrix B is bigger\n");
        Aver(ab, nb, b, mb);
        AnsOut(ab, nb, file0);
  }

  if ((ca == 0) && (cb == 0))
  {
    fprintf(file0, "Nonzero elements of matrix A and matrix B were not found\n");
  }

  fclose(file0);
  
  printf("Program ended, press any key to close\n");
  while (!kbhit()){}
  return 0;
}

void ArrayInput(int &n, int &m, int x[][MMAX], FILE *file)
{
  fscanf(file, "%d %d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      fscanf(file, "%d", &x[i][j]);
    } 
  return;
  } 

void ArrayOut(int n, int m, int x[][MMAX], FILE *file, char a)
{ 
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

int Comp(int x[][MMAX], int n, int m)
{ 
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

void Aver(double a[], int n, int x[][MMAX], int m)
{ 
  int k = 0;
  for (int i = 0; i < n; i++){
    a[i] = 0;
    for (int j = 0; j < m; j++)
      if (x[j] != 0){
        a[i] += x[i][j];
        k++;
      }
    if (a[i] != 0)
      a[i] = a[i] / k;
  }
  return;
}

void AnsOut(double a[], int n, FILE *file){
  for (int i = 0; i < n; i++){
    fprintf(file, "Average of nonzero elements of line %d: %8.4f\n", i, a[i]);
  }
  return;
}
