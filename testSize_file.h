void testSize_file() {

  int res[] = {62, 75, 51408};
  char *names[] = {"doc62", "doc75", "doc51_408"};

  int F = 1;
  for (int i = 0; i < 3; i++) {

    int cur_res = size_file(names[i]);

    if (cur_res != res[i]) {
      F = 0;
      printf("size_file\ntest %d failed\n", i + 1);
      printf("for file %s\n", names[i]);
      printf("Expected: %d\nFound: %d\n", res[i], cur_res);
    }

  }

  if(F)
    printf("All size_file tests have been passed\n");

}
