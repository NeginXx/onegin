void testQ_sort() {

  char* ptrarray1[] = {"723", "956", "aaaa"};
  char* ptrarray2[] = {"sad ,c,", "SaD  mlll", "11", "\t5"};
  char* ptrarray3[] = {"kdd", "Yizzz", "yikes", "88", "a4A4Akk"};

  char* res1[] = {"723", "956", "aaaa"};
  char* res2[] = {"11", "\t5", "sad ,c,", "SaD  mlll"};
  char* res3[] = {"88", "a4A4Akk", "kdd", "yikes", "Yizzz"};

  q_sort((void*) ptrarray1, 0, 2, str_cmp_forward);
  q_sort((void*) ptrarray2, 0, 3, str_cmp_forward);
  q_sort((void*) ptrarray3, 0, 4, str_cmp_forward);

  int F = 1;
  int f = 0;
  for (int i = 0; i < 3; i++)
    if (strcmp(ptrarray1[i], res1[i]))
      f = 1;

  if (f) {

    F = 0;

    printf("q_sort\ntest %d failed\n", 1);
    printf("for string array: ");

    for (int i = 0; i < 3; i++)
      printf("%s\n", ptrarray1[i]);

  }

  f = 0;
  for (int i = 0; i < 4; i++)
    if (strcmp(ptrarray2[i], res2[i]))
      f = 1;

  if (f) {

    F = 0;

    printf("q_sort\ntest %d failed\n", 2);
    printf("for string array: ");

    for (int i = 0; i < 4; i++)
      printf("%s\n", ptrarray2[i]);

  }

  f = 0;
  for (int i = 0; i < 5; i++)
    if (strcmp(ptrarray3[i], res3[i]))
      f = 1;

  if (f) {

    F = 0;

    printf("q_sort\ntest %d failed\n", 3);
    printf("for string array: ");

    for (int i = 0; i < 5; i++)
      printf("%s\n", ptrarray3[i]);

  }

  if(F)
    printf("All q_sort tests have been passed\n");

}
