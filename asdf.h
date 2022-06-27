#ifndef ASDF_H
#define ASDF_H

#define CONST1 1
#define CONST2 2
#define CONST3 3

enum {
  ENUM1 = 1,
  ENUM4 = 4,
  ENUM5,
  ENUM6
};


struct mystruct {
  int intfield;
  char charfield;
};

struct mystruct* create();

#endif /* ASDF_H */