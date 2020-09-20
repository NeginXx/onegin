#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define FORWARD 0
#define BACKWARD 1

/*!
Returns a position of a pivot and partitions given array around the pivot
\param arr Array of void pointers
\param low, high, mid Indexes
\param comp Pointer on comparator function
\return Index of a pivot after partitioning
*/
int partition(void* arr[], int low, int high, int mid, int (*comp)(void *, void *));
/*!
Sorts a given array using a given pointer on a comparator function
\param arr Array of void pointers
\param low, high Indexes
\param comp Pointer on comparator function
*/
void q_sort(void* arr[], int low, int high, int (*comp)(void *, void *));
/*!
Swaps two elements with given indexes in given array
\param arr Array of void pointers
\param i, j Indexes
*/
void swap(void* arr[], int i, int j);
/*!
Comparator function, works like strcmp but from the end to the start, with no
respect to non-letter symbols and register of a letter
\param aa, bb Two strings
\return Returns negative number if aa is less than bb from the end to the start,
positive if bigger and 0 if equal
*/
int str_cmp_forward(void* aa, void* bb);
/*!
Comparator function, works like strcmp but with no respect to non-letter symbols
and register of a letter
\param aa, bb Two strings
\return Returns negative number if aa is less than bb,
positive if bigger and 0 if equal
*/
int str_cmp_backward(void* aa, void* bb);
/*!
Constructs array of strings given a file written in string and size of a file in bytes
\param ptrarray Array to be constructed
\param sz Size of file in bytes
\param str String representing a file
*/
void construct_ptrarray(char** ptrarray, size_t sz, char* str);
/*!
Outputs an array of strings to output file
\param ptrarray Array to be outputed
\param lines Number of lines in a file or size of ptrarray
\param output File to write in
\param keyword If keyword == FORWARD array is written as it sorted with str_cmp_forward
if keyword == BACKWARD array is written as it sorted with str_cmp_backward
*/
void ptrarray_out(char** ptrarray, int lines, FILE* output, int keyword);
/*!
Finds a pointer to the beginning of the string that precedes given char* pointer
\return Pointer to the beginning of the string
*/
char* find_start(char* ptr);

/*!
Calculates the size of a given file
\param name Name of a file
\return Size of a file in bytes
*/
size_t size_file(char* name);
/*!
Finds a number of lines in a file that is given a string
\param str Pointer to the string that represents a file
\return Number of lines in a file
*/
int count_lines(char* str);

#include "testOnegin.h"

int main() {

  testOnegin();

  char name[] = "textin";
  size_t sz = size_file(name);
  assert(sz > 0 && sz < 500000);

  FILE* input = fopen("textin", "r");
  assert(input != NULL);

  char* string_file = (char*) calloc(sz + 2, sizeof (char));
  string_file[0] = '\0';
  fread(string_file + 1, sizeof(char), sz, input);
  string_file[sz] = '\0';
  string_file[sz + 1] = '\0';

  fclose(input);

  int lines = count_lines(string_file); //counts lines and replaces '\n' with '\0'
  char** ptrarray = (char**) calloc(lines + 1, sizeof(char**));
  construct_ptrarray(ptrarray, sz, string_file);
  *(ptrarray + lines) = string_file + sz + 1;

  q_sort((void*) ptrarray, 0, lines - 1, str_cmp_forward);

  FILE* output = fopen("textout", "w");
  assert(output != NULL);

  ptrarray_out(ptrarray, lines, output, FORWARD);

  q_sort((void*) ptrarray, 1, lines, str_cmp_backward);

  ptrarray_out(ptrarray, lines, output, BACKWARD);

  fclose(output);

  return 0;

}

char* find_start(char* ptr) {

  assert(ptr != NULL);

  ptr -= 2;
  for(; *ptr != '\0'; ptr--);

  return ptr + 1;

}

void ptrarray_out(char** ptrarray, int lines, FILE* output, int keyword) {

  assert(ptrarray != NULL && *ptrarray != NULL && output != NULL);
  assert(keyword == FORWARD || keyword == BACKWARD);

  if (keyword == FORWARD) {

    for (int i = 0; i < lines; i++) {
      if (**(ptrarray + i) != '\0') { // != '\0' so no empty lines are written
        fputs(*(ptrarray + i), output);
        fputc('\n', output);
      }
    }

  }

  else {

    for (int i = 1; i <= lines; i++) {

      char* ptr = *(ptrarray + i);
      if (*(ptr = find_start(ptr)) != '\0') { // != '\0' so no empty lines are written

        fputs(ptr, output);
        fputc('\n', output);

      }

    }

  }

  if (keyword == FORWARD) {
    fputs("\n\n\n\n", output);
    for (int i = 0; i < 10; i++)
      fputs("-----------------------------------------------\n\n\n\n", output);
  }

}

void construct_ptrarray(char** ptrarray, size_t sz, char* str) {

  assert(ptrarray != NULL);
  assert(str != NULL);

  *ptrarray = str + 1;

  if (*(str + 1) == '\n')
    str++;

  int i = 1;
  while ((str = strchr(str + 1, '\n')) != NULL) {
    *(ptrarray + i++) = str + 1;
    *str = '\0';
  }

}

int count_lines(char* str) {

  assert(str != NULL);

  int cnt = 0;
  while((str = strchr(++str, '\n')) != NULL)
    cnt++;

  return cnt + 1;

}

size_t size_file(char* name) {

  assert(name != NULL);

  struct stat buf;
  stat(name, &buf);

  return buf.st_size;

}

void swap(void* arr[], int i, int j) {

  assert(arr != NULL && arr[i] != NULL && arr[j] != NULL);

  void* temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;

}

int str_cmp_backward(void* aa, void* bb) {

  assert(aa != NULL && bb != NULL);

  char* a = (char*) aa;
  char* b = (char*) bb;
  char atemp = '\0', btemp = '\0';

  a -= 2;
  b -= 2;

  while(1) {

    while(!isalnum(*a) && *a != '\0')
      a--;

    while(!isalnum(*b) && *b != '\0')
      b--;

    if (*a == '\0' && *b == '\0')
      break;

    atemp = *a;
    atemp = (char) tolower(atemp);

    btemp = *b;
    btemp = (char) tolower(btemp);

    if (atemp != btemp)
      break;

    a--; b--;

  }

  return atemp - btemp;

}

int str_cmp_forward(void* aa, void* bb) {

  assert(aa != NULL && bb != NULL);

  char* a = (char*) aa;
  char* b = (char*) bb;
  char atemp = '\0', btemp = '\0';

  while(1) {

    while(!isalnum(*a) && *a != '\0')
      a++;

    while(!isalnum(*b) && *b != '\0')
      b++;

    if (*a == '\0' && *b == '\0')
      break;

    atemp = *a;
    atemp = (char) tolower(atemp);

    btemp = *b;
    btemp = (char) tolower(btemp);

    if (atemp != btemp)
      break;

    a++; b++;

  }

  return atemp - btemp;

}

int partition(void* arr[], int low, int high, int mid, int (*comp)(void *, void *)) {

  assert(arr != NULL && low < high && comp != NULL);

  swap(arr, low, mid);

  int last = low;
  for (int i = low + 1; i <= high; i++)
    if ((*comp)(arr[i], arr[low]) < 0)
      swap(arr, ++last, i);

  swap(arr, low, last);

  return last;

}

void q_sort(void* arr[], int low, int high, int (*comp)(void *, void *)) {

  assert(arr != NULL && comp != NULL);

  if (high - low <= 0)
    return;

  int mid = (high + low) / 2;

  int p = partition(arr, low, high, mid, comp);
  q_sort(arr, low, p - 1, comp);
  q_sort(arr, p + 1, high, comp);


}
