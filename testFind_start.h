void testFind_start() {

  char *strings[] = {"\0kk\0mma1", "\0\0j\0m", "\0q1 kw \t,\0m"};
  char* res[] = {strings[0] + 1, strings[1] + 2, strings[2] + 1};
  char* inp[] = {strings[0] + 4, strings[1] + 4, strings[2] + 10};

  int F = 1;
  for (int i = 0; i < 3; i++) {

    if (find_start(inp[i]) != res[i]) {

      F = 0;
      printf("find_start\ntest %d failed\n", i + 1);
      printf("for string %s\n", res[i]);

    }

  }

  if(F)
    printf("All find_start tests have been passed\n");

}
