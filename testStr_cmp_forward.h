void testStr_cmp_forward() {

  char arr[][200] = {"1 2,, 3 bBCc 03", "123  ../ bbcc03", "iIi77", "iii777", "        .899 //AtAiii0", " 8,,,9,9 ataiiI", "8Uu,9uu kK   ,..,,,,.,,.,/. . ., ,. ", "8UU,9uuKK", "A"};
  int res[] = {0, -55, 48, 0};

  int F = 1;
  for (int i = 0; i < 4; i++) {

    int cur_res = str_cmp_forward(arr[i*2], arr[i*2 + 1]);

    if (cur_res != res[i]) {
      F = 0;
      printf("str_cmp_forward\ntest %d failed\n", i + 1);
      printf("for strings %s   and   %s\n", arr[i*2], arr[i*2 + 1]);
      printf("Expected: %d\nFound: %d\n", res[i], cur_res);
    }

  }

  if(F)
    printf("All strcmp_forward tests have been passed\n");

}
