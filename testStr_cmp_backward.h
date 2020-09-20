void testStr_cmp_backward() {

  char s[] = "\0dk + kde\0m 32 mm 1; ; kdsa\0 ,d,1 nnAA\0a,d1NNaA\0n55z,,d382";
  char *p1 = s + 10, *p2 = s + 28, *p3 = s + 39;
  int res[] = {4, 18, -4};

  int F = 1;
  if (str_cmp_backward(p1, p2) != 4) {
    F = 0;
    printf("str_cmp_backward\ntest %d failed\n", 1);
    printf("for strings dk + kde   and  m 32 mm 1; ; kdsa\n");
    printf("Expected: %d\nFound: %d\n", 4, str_cmp_backward(p1, p2));
  }

  if (str_cmp_backward(p2, p3) != 18) {
    F = 0;
    printf("str_cmp_backward\ntest %d failed\n", 2);
    printf("for strings m 32 mm 1; ; kdsa    and     ,d,1 nnAA\n");
    printf("Expected: %d\nFound: %d\n", 18, str_cmp_backward(p2, p3));
  }

  if (str_cmp_backward(p3, p1) != -4) {
    F = 0;
    printf("str_cmp_backward\ntest %d failed\n", 3);
    printf("for strings  ,d,1 nnAA    and   m 32 mm 1; ; kdsa\n");
    printf("Expected: %d\nFound: %d\n", -4, str_cmp_backward(p3, p1));
  }

  if(F)
    printf("All strcmp_backward tests have been passed\n");

}
