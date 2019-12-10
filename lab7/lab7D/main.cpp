#include <conio.h>
#include <iostream>
#include <windows.h>

typedef void (*Order)(FILE * , char *&, int &);
typedef void (*Flip)(char * , char *& , int , int );

int main(int argc, char *argv[]){
  FILE *file;

  HINSTANCE hLib = LoadLibrary(TEXT("dllmain.dll"));
  Order OrderString = (Order)GetProcAddress(hLib, "OrderString");
  Flip FlipString = (Flip)GetProcAddress(hLib, "FlipString");

  file = fopen(argv[2], "r");
  char* str = new char[0];
  int length = 0;

  OrderString(file, str, length);

  fclose(file);
  char* str2 = new char[length + 1];
  int length2 = 0;

  FlipString(str, str2, length - 1, length2);

  str2[length] = '\0';
  file = fopen(argv[1], "w");

  fprintf(file, "Source string: %s \n", str);
  fprintf(file, "Flipped string: %s\n", str2);
  fclose(file);
  
  delete[] str2;
  delete[] str;

  FreeLibrary(hLib);

  printf("Program ended, press any key to close\n");
  while (!kbhit()){}
  return 0;
  }