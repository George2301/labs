#include <cstdio>
#include <locale.h>
#include <conio.h>

int const NMAX = 6;
typedef double arr[NMAX];

bool IsRecord(int i, int k){
  bool f = false;
  if ((i >= 0) && (i < k))
    f = true;
  return f;
}

void FromTextToBin(FILE *file, FILE *fbin, int &k){
  arr x;
  k = 0;
  while (!feof(file)){
    if (fscanf(file, "%lf %lf %lf %lf %lf %lf", &x[0], &x[1], &x[2], &x[3], &x[4], &x[5]) == NMAX){
      k++;
      fwrite(x, sizeof(arr), 1, fbin);
    }
  }
  return;
}

void FromBinToText(FILE *fbin, FILE *file, int k){
  arr x;
	fseek(file,  0 , SEEK_SET);
  for (int i = 0; i < k ; i++){
    fread(x, sizeof(arr), 1, fbin);
    for (int i = 0; i < NMAX; i++)
      fprintf(file, "%lf ", x[i]);
  fprintf(file, "\n");
	}
	return;
}

void Swap(int i, int j, FILE* file){
	arr x, y;
  
    fseek(file,  i * sizeof(arr), SEEK_SET);
    fread(x, sizeof(arr), 1, file);

    fseek(file, j * sizeof(arr), SEEK_SET);
    fread(y, sizeof(arr), 1, file);

    fseek(file, i * sizeof(arr), SEEK_SET);
    fwrite(y, sizeof(arr), 1, file);

    fseek(file, j * sizeof(arr), SEEK_SET);
    fwrite(x, sizeof(arr), 1, file);
  
  return;
}

int main(int argc, char *argv[]){
  FILE *file1, *file0, *fbin;
  int i, j, k;

  file1 = fopen(argv[2], "r");
  fbin = fopen(argv[3], "wb");
  FromTextToBin(file1, fbin, k);
  fclose(file1);
  fclose(fbin);

  fbin = fopen(argv[3], "rb");
  file0 = fopen(argv[1], "w");
  FromBinToText(fbin, file0, k);
  fprintf(file0, "\n");
  fclose(file0);
  fclose(fbin);

  printf("Input numbers of records needed to be changed \n");
  scanf("%d %d", &i, &j);
  fbin = fopen(argv[3], "r+b");
  if (IsRecord(i, k) && IsRecord(j, k)){
    Swap(i, j, fbin);
  } else {
    printf("Record was not found \n");
  }
  fclose(fbin);

  fbin = fopen(argv[3], "rb");
  file0 = fopen(argv[1], "a");
  FromBinToText(fbin, file0, k);
  fclose(file0);
  fclose(fbin);

  printf("Program ended, press any key to close\n");
  while (!kbhit()){}
  return 0;
}