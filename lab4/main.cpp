#include <iostream>
bool CheckChar(char ch){ return (((ch >= '0') && (ch <= '9')) || ((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z'))); }
void PasteSymbol(char* &str, int &length, char c){
  char* new_str = new char[length + 2];
  for (int i = 0; i < length; i++) new_str[i] = str[i];
  delete[] str;
  new_str[length] = c;
  new_str[length + 1] = '\0';
  str = new_str;
  length = length + 1;
  return;}
void OrderString(FILE* file, char* &str, int &length){
  if (!(feof(file))){
    char c;
    fscanf(file, "%c", &c);
    if (CheckChar(c) && !(feof(file))) PasteSymbol(str, length, c);
    else if((length > 0) && (str[length - 1] != ' ') && !(feof(file))){
      c = ' ';
      PasteSymbol(str, length, c);
    }
    OrderString(file, str, length);
  } else return;}
void LengthOfLastWord(char* str, int& length, int& k){
  if (str[length] != ' ' && length >= 0){
    k++;
    length--;
    LengthOfLastWord(str, length, k);
  } else return;}
void WriteLastWord(char* str, char*& str2, int& length, int length2, int k) {
  if (length2 < k){
    str2[length2] = str[length + 1];
    length++;
    WriteLastWord(str, str2, length, length2 + 1, k);
  } else return;}
void FlipString(char* str, char*& str2, int length, int length2){
  if (length >= 0){
    int k = 0;
    LengthOfLastWord(str, length, k);
    WriteLastWord(str, str2, length, length2, length2 + k);
    str2[length2 + k] = ' ';
    length2 = length2 + k + 1;
    length = length - k - 1;
    FlipString(str, str2, length, length2);
  } else return;}
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
  delete[] str2; delete[] str;
  return 0;}