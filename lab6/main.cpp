#include <cstdio>
#include <locale.h>
#include <conio.h>

bool Check(int p, int n){
  return (0 <= p && p < 32) && (n >= 0) && (p - n >= 0);
}

const int bits = sizeof(int) * 8;

unsigned int MakeMask(int p, int n){
  unsigned int mask = 0xFFFFFFFF;
  mask = (mask >> bits - n - 1) << (p - n);
  return mask;
}

int ChangeBits(int a, int p, int n){
  unsigned int mask = MakeMask(p , n);
  return a | mask;
}

void HexBitOut(int a, int b){
  printf("Hex:\n");
  printf("A = %08x, Result = %08x:\n", a, b);
}

int main(int argc, char *argv[]){
  int a, res;
  int p, n;
  printf("Enter A:\n");
  scanf("%d", &a);
  printf("Enter P and N:\n");
  scanf("%d %d", &p, &n);

  if(Check(p, n)){
    res = ChangeBits(a, p, n);
    printf("Res: %d\n", res);
    HexBitOut(a, res);
  } else 
    printf("Incorrect P and N:\n");

  printf("Program ended, press any key to close\n");
  while (!kbhit()){}
  return 0;
}