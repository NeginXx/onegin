void testCount_lines() {

  int res[] = {3, 4, 2};
  char strings[][8] = {{'1', '\n', '1', '\n'}, {'\t', '/', '5', '\n', ' ', ' ', '5', '\n'}, {'1', '\n'}};

  int F = 1;
  for (int i = 0; i < 3; i++) {

    int cur_res = count_lines(strings[i]);

    if (cur_res != res[i]) {
      F = 0;
      printf("count_lines\ntest %d failed\n", i + 1);
      printf("for string %s\n", strings[i]);
      printf("Expected: %d\nFound: %d\n", res[i], cur_res);
    }

  }

  if(F)
    printf("All count_lines tests have been passed\n");

}
