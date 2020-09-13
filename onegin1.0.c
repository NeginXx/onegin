#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100000

void swap_ptrs(char** a, char** b);
int str_cmp(char* a, char* b);
int partition(char** arr, int low, int high, int mid, int (*comp)(char *, char *));
void q_sort(char** arr, int low, int high, int (*comp)(char *, char *));
void construct(FILE* input, char* string_file, char** ptrarray, int* NumberOfLines);
int readline(FILE* input, char** ptr);
void out(FILE* output, char** ptrarray, int lines);

int main() {

  char string_file[MAXSIZE];
  char* ptrarray[MAXSIZE];
  FILE* input = fopen("textin", "r");
  FILE* output = fopen("textout", "w");

  int lines = 0;
  construct(input, string_file, ptrarray, &lines);
  q_sort(ptrarray, 0, lines - 1, str_cmp);
  out(output, ptrarray, lines);

  fclose(input);
  fclose(output);

  return 0;

}

void out(FILE* output, char** ptrarray, int lines) {

  char* p;
  for (int i = 0; i < lines; i++) {

    p = *(ptrarray + i);
    char c;
    int j = 0;

    do {
      c = fputc(*(p + j++), output);
    } while(c != '\n');

  }

  return;

}

int readline(FILE* input, char** ptr) {

  char c;
  while ((c = fgetc(input)) != '\n' && c != EOF) {
    **ptr = c;
    (*ptr)++;
  }

  if (c == '\n') {
    **ptr = c;
    (*ptr)++;
    return 1;
  }

  if (c == EOF) {
    **ptr = '\n';
    (*ptr)++;
    return 0;
  }


}

void construct(FILE* input, char* string_file, char** ptrarray, int* NumberOfLines) {

  *NumberOfLines = 0;
  char* ptr = string_file;    //ptr points on the next free cell in string_file
  *ptrarray = ptr;

  if (!readline(input, &ptr)) {      //file's empty
    fprintf(stderr, "Empty file\n");
    return;
  }

  int i = 1;
  do {
    *(ptrarray + i) = ptr;
    i++;
    (*NumberOfLines)++;
  } while(readline(input, &ptr));

  *(ptrarray + i) = ptr;  //this ptr is the end of file

  return;

}

void swap_ptrs(char** a, char** b) {

  char* temp = *a;
  *a = *b;
  *b = temp;

  return;

}

int str_cmp(char* a, char* b) {

  for(; *a == *b; a++, b++)
    if (*a == '\n')
      return 0;

  return *a - *b;

}

int partition(char** arr, int low, int high, int mid, int (*comp)(char *, char *)) {

  swap_ptrs(arr + low, arr + mid);

  int last = low, i;
  for (i = low + 1; i <= high; i++)
    if (comp(arr[i], arr[low]) < 0)
      swap_ptrs(arr + ++last, arr + i);

  swap_ptrs(arr + low, arr + last);

  return last;
}

void q_sort(char** arr, int low, int high, int (*comp)(char *, char *)) {

  if (high - low <= 0)
    return;

  int mid = low + (high - low) / 2;

  int p = partition(arr, low, high, mid, comp);
  q_sort(arr, low, p - 1, comp);
  q_sort(arr, p + 1, high, comp);

  return;

}
