void testSwap() {

  char *arr1[] = {"123", "456"};
  int arr2[] = {5, 1};
  int F = 1;
  swap((void*) arr1, 0, 1);
  swap((void*) arr2, 1, 0);

  if (!strcmp(arr1[0], "456") && !strcmp(arr1[1], "123") && arr2[0] == 1 && arr2[1] == 5)
    printf("All swap tests have been passed\n");

  else {
    printf("swap function failed tests!!!!!!!!!!!!!\n");
  }

}
