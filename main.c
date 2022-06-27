#include <stdio.h>
#include "asdf.h"

int main () {
  printf("llvm-pass example\n");
  struct mystruct *a = create();
  printf("a->intfield: %d\n", a->intfield);
  printf("a->charfield: %d\n", a->charfield);

  return 0;
}