#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100000

void swap_ptrs(char** a, char** b);
int str_cmp(char* a, char* b);
int partition(char** arr, int low, int high, int mid, int (*comp)(char *, char *));
void q_sort(char** arr, int low, int high, int (*comp)(char *, char *));
void construct_ptrarray(char** ptrarray, int sz, char* str);
void out(char** ptrarray, int lines);
int size_file(FILE* input);
int count_lines(char* str, int sz);

int main() {

  char* string_file;
  FILE* input = fopen("doc1", "r");
  int sz = size_file(input);

  string_file = (char*) calloc(sz + 1, 1);
  fread(string_file, 1, sz, input);
  fclose(input);

  int lines = count_lines(string_file, sz);
  char** ptrarray = (char**) calloc(lines, 8);

  construct_ptrarray(ptrarray, sz, string_file);
  q_sort(ptrarray, 0, lines - 1, str_cmp);
  out(ptrarray, lines);


  return 0;

}

void out(char** ptrarray, int lines) {

  FILE* output = fopen("textout", "w");

  for (int i = 0; i < lines; i++) {
    fputs(*(ptrarray + i), output);
    fputc('\n', output);
  }

  fclose(output);

  return;

}

void construct_ptrarray(char** ptrarray, int sz, char* str) {

  *ptrarray = str;
  int j = 1;
  for (int i = 0; i <= sz - 2; i++) {
    if (str[i] == '\0') {
      ptrarray[j++] = str + i + 1;
    }
  }

  return;
}

int count_lines(char* str, int sz) {

  int lines = 0;
  for (int i = 0; i < sz; i++) {
    if (*(str + i) == '\n') {
      lines++;
      *(str + i) = '\0';
    }
  }

  return lines;

}

int size_file(FILE* input) {

  fseek(input, 0, SEEK_END);
  int sz = ftell(input);
  fseek(input, 0, SEEK_SET);

  return sz;

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
