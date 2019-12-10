#include <cstdio>
#include <locale.h>
#include <conio.h>
#include <cmath>

const int NMAX = 10; 

typedef double (*PF)(double);

PF func;

void MinElem(int x[], int nn, double n, double &min, int &y, PF func){
  int i = 0;
  bool f = false;
  min = n;

  while (i < nn){
    if ((func(x[i]) > n) && !f){
      f = true; 
      min = func(x[i]);
      y = x[i];
    }
    if ((func(x[i]) > n) && f && (func(x[i]) < min)){
      min = func(x[i]);
      y = x[i];
    }
    i++;
  }
  if (!f) 
    min = n;
  }

void ArrayInput(int &n, int x[], FILE *file){
  fscanf(file, "%d", &n);
  for (int i = 0; i < n; i++)
    fscanf(file, "%d", &x[i]); 
  return;
} 

void ArrayOut(int n, int x[], FILE *file, char a){ 
  fprintf(file, "Array %c:\n", a);
  fprintf(file, "Amount of elements %d\n", n);
  for (int i = 0; i < n; i++)
    fprintf(file, "%d, ", x[i]);
  fprintf(file, "\n");
  return ;
}

void AnsOut(double aa, int ya, double ab, int yb, double ac, int yc, double n, PF func, FILE *file){ 
  fprintf(file, "Given n: %f\n", n);
  if (aa > ab && aa > ac && aa != n)
    fprintf(file, "Array А has bigger minimal element, that bigger than given element: %f = f(%d)\n", aa, ya);
  if (ab > aa && ab > ac && ab != n)
    fprintf(file, "Array B has bigger minimal element, that bigger than given element: %f = f(%d)\n", ab, yb);
  if (ac > aa && ac > ab && ac != n)
    fprintf(file, "Array C has bigger minimal element, that bigger than given element: %f = f(%d)\n", ac, yc);
  if (aa == ab && aa > ac && aa != n)
    fprintf(file, "Array А and B has bigger minimal element, that bigger than given element: %f = f(%d)\n", aa, ya);
  if (aa == ac && aa > ab && aa != n)
    fprintf(file, "Array A and C has bigger minimal element, that bigger than given element: %f = f(%d)\n", aa, ya);
  if (ab == ac && ab > aa && ab != n)
    fprintf(file, "Array B and C has bigger minimal element, that bigger than given element: %f = f(%d)\n", ab, yb);
  if (aa == ab && aa == ac && aa != n)
    fprintf(file, "Array A and B an C has bigger minimal element, that bigger than given element: %f = f(%d)\n", aa, ya);
  if(aa == n && ab == n && ac == n)
    fprintf(file, "Elements bigger than given were not found\n");
  return;
}

int main(int argc, char *argv[])
{ int a[NMAX], b[NMAX], c[NMAX];
  double aa, ab, ac, n;
  int na, nb, nc, ya, yb, yc;
  FILE *file1, *file2, *file3, *file4;
  file1 = fopen(argv[1], "r"); 
  file2 = fopen(argv[2], "r");
  file3 = fopen(argv[3], "r");

  ArrayInput(na, a, file1);
  ArrayInput(nb, b, file2);
  ArrayInput(nc, c, file3);

  fclose(file1);
  fclose(file2);
  fclose(file3);

  file4 = fopen(argv[4], "w");

  ArrayOut(na, a, file4, 'A');
  ArrayOut(nb, b, file4, 'B');
  ArrayOut(nc, c, file4, 'C');

  printf("Enter a number\n");
  scanf("%lf", &n);
  
  fprintf(file4, "Sin: \n");
  func = sin;
  MinElem(a, na, n, aa, ya, func);
  MinElem(b, nb, n, ab, yb, func);
  MinElem(c, nc, n, ac, yc, func);

  AnsOut(aa, ya, ab, yb, ac, yc, n, func, file4);

  fprintf(file4, "Exp: \n");
  func = exp;
  MinElem(a, na, n, aa, ya, func);
  MinElem(b, nb, n, ab, yb, func);
  MinElem(c, nc, n, ac, yc, func);
  
  AnsOut(aa, ya, ab, yb, ac, yc, n, func, file4);

  fprintf(file4, "Log: \n");
  func = log;
  MinElem(a, na, n, aa, ya, func);
  MinElem(b, nb, n, ab, yb, func);
  MinElem(c, nc, n, ac, yc, func);

  AnsOut(aa, ya, ab, yb, ac, yc, n, func, file4);
  fclose(file4);

  printf("Program ended, press any key to close\n");
  while (!kbhit()){}
  return 0;
  }