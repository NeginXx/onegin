void testPartition() {

  int p1, p2, p3;

  char* ptrarray1[] = {"723", "956", "aaaa"};
  char* ptrarray2[] = {"sad ,c,", "SaD  mlll", "11", "\t5"};
  char* ptrarray3[] = {"kdd", "Yizzz", "yikes", "88", "a4A4Akk"};

  char* res1[] = {"723", "956", "aaaa"};
  char* res2[] = {"11", "SaD  mlll", "sad ,c,", "\t5"};
  char* res3[] = {"a4A4Akk", "kdd", "88", "yikes", "Yizzz"};

  p1 = partition((void*) ptrarray1, 0, 2, 1, str_cmp_forward);
  p2 = partition((void*) ptrarray2, 0, 3, 2, str_cmp_forward);
  p3 = partition((void*) ptrarray3, 0, 4, 2, str_cmp_forward);

  int F = 1;
  int f = 0;
  for (int i = 0; i < 3; i++)
    if (strcmp(ptrarray1[i], res1[i]))
      f = 1;

  if (p1 != 1 || f) {

    F = 0;

    printf("partition\ntest %d failed\n", 1);
    printf("for string array: ");

    for (int i = 0; i < 3; i++)
      printf("%s\n", ptrarray1[i]);

  }

  f = 0;
  for (int i = 0; i < 4; i++)
    if (strcmp(ptrarray2[i], res2[i]))
      f = 1;

  if (p2 != 0 || f) {

    F = 0;

    printf("partition\ntest %d failed\n", 2);
    printf("for string array: ");

    for (int i = 0; i < 4; i++)
      printf("%s\n", ptrarray2[i]);

  }

  f = 0;
  for (int i = 0; i < 5; i++)
    if (strcmp(ptrarray3[i], res3[i]))
      f = 1;

  if (p1 != 1 || f) {

    F = 0;

    printf("partition\ntest %d failed\n", 3);
    printf("for string array: ");

    for (int i = 0; i < 5; i++)
      printf("%s\n", ptrarray1[i]);

  }

  if(F)
    printf("All partition tests have been passed\n");

}
