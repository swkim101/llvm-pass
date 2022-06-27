#include <stdlib.h>
#include "asdf.h"

struct mystruct* create() {
  struct mystruct *s = (struct mystruct*)malloc(sizeof(struct mystruct));
  s->intfield = CONST1;
  s->charfield = ENUM4;

  return s;
}