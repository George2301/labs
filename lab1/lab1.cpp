#include <cstdio>
#include <locale.h>
#include <conio.h>

const int NMAX = 10; 

int MinElem(int x[], int nn, int n)
{ int i = 0;
  bool f = false;
  int min = n;

  while (i < nn)
  {
    if ((x[i] > n) && !f)
    {
      f = true; 
      min = x[i];
    }
    if ((x[i] > n) && f && (x[i] < min))
      min = x[i];
    i++;
  }
  if (f) 
    return min;
  else
    return n;
  }

int ArrayInput(int &n, int x[], FILE *file)
  {
  fscanf(file, "%d", &n);
  for (int i = 0; i < n; i++)
    fscanf(file, "%d", &x[i]); 
  return 0;
  } 

int ArrayOut(int n, int x[], FILE *file, char a)
{ 
  fprintf(file, "Array %c:\n", a);
  fprintf(file, "Amount of elements %d\n", n);
  for (int i = 0; i < n; i++)
    fprintf(file, "%d, ", x[i]);
  fprintf(file, "\n");
  return 0;
}

int AnsOut(int aa, int ab, int ac, int n, FILE *file)
{ 
  if (aa > ab && aa > ac && aa != n)
    fprintf(file, "Array А has bigger minimal element, that bigger than given element: %d\n", aa);
  if (ab > aa && ab > ac && ab != n)
    fprintf(file, "Array B has bigger minimal element, that bigger than given element: %d\n", ab);
  if (ac > aa && ac > ab && ac != n)
    fprintf(file, "Array C has bigger minimal element, that bigger than given element: %d\n", ac);
  if (aa == ab && aa > ac && aa != n)
    fprintf(file, "Array А and B has bigger minimal element, that bigger than given element: %d\n", aa);
  if (aa == ac && aa > ab && aa != n)
    fprintf(file, "Array A and C has bigger minimal element, that bigger than given element: %d\n", aa);
  if (ab == ac && ab > aa && ab != n)
    fprintf(file, "Array B and C has bigger minimal element, that bigger than given element: %d\n", ab);
  if (aa == ab && aa == ac && aa != n)
    fprintf(file, "Array A and B an C has bigger minimal element, that bigger than given element: %d\n", aa);
  if(aa == n && ab == n && ac == n)
    fprintf(file, "Elements bigger than given were not found\n");
  return 0;
}

int main(int argc, char *argv[])
  { int a[NMAX], b[NMAX], c[NMAX];
    int aa, ab, ac, na, nb, nc, n;
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
  scanf("%d", &n);
  
  aa = MinElem(a, na, n);
  ab = MinElem(b, nb, n);
  ac = MinElem(c, nc, n);

  AnsOut(aa, ab, ac, n, file4);
  fclose(file4);

  printf("Program ended, press any key to close\n");
  while (!kbhit()){}
  return 0;
  }