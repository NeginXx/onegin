void testConstruct_ptrarray() {

  char res[][4] = {{'j', 'n', 'k', ' '}, {'1'}, {'8', 'i', 'p'}};
  char *strings[] = {"jjj\0n55\0kk\0   \0", "1\0", "88,\0ii   \0p1\0"};
  int sizes[] = {15, 2, 13};
  int lines[] = {4, 1, 3};

  int F = 1;
  for (int i = 0; i < 3; i++) {

    char** ptrarray = (char**) calloc(lines[i], sizeof(char**));
    construct_ptrarray(ptrarray, sizes[i], strings[i]);

    int FF = 1;
    for (int j = 0; j < lines[i]; j++) {
      if (res[i][j] != **(ptrarray + j) && FF) {
        FF = 0;
        F = 0;
        printf("construct_ptrarray\ntest %d failed\n", i + 1);
        printf("for string %s\n", strings[i]);
        printf("Expected in ptrarray: %c\nFound: %c\n", res[i][j], **(ptrarray + j));
      }
    }
  }

  if(F)
    printf("All construct_ptrarray tests have been passed\n");

}
