#include "testPartition.h"
#include "testQ_sort.h"
#include "testSwap.h"
#include "testStr_cmp_backward.h"
#include "testStr_cmp_forward.h"
#include "testFind_start.h"
#include "testConstruct_ptrarray.h"
#include "testCount_lines.h"
#include "testSize_file.h"
void testOnegin() {
  testPartition();
  testQ_sort();
  testStr_cmp_forward();
  testStr_cmp_backward();
  testFind_start();
  testSize_file();
  testCount_lines();
}
