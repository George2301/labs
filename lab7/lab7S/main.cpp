#include <conio.h>
#include <iostream>

//#include "dllmain.dll"

extern "C" __declspec(dllimport) void OrderString(FILE *file, char *&str, int &length);
extern "C" __declspec(dllimport) void FlipString(char *str, char *&str2, int length, int length2);

int main(int argc,char *argv[]){
  FILE *file;

  file = fopen(argv[2], "r");
  char* str = new char[0];
  int length = 0;

  OrderString(file, str, length);

  fclose(file);
  char* str2 = new char[length+1];
  int length2 = 0;

  FlipString(str, str2, length-1, length2);

  str2[length] = '\0';
  file = fopen(argv[1], "w");

  fprintf(file, "Source string: %s \n", str);
  fprintf(file, "Flipped string: %s\n", str2);
  fclose(file);
  
  delete[] str2;
  delete[] str;
  
  printf("Program ended, press any key to close\n");
  while (!kbhit()){}
  return 0;
  }