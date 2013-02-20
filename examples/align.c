
#include <stdio.h>
#include <stdlib.h>

struct data_naive {
  short s;
  int i;
  char c;
};

struct data_align {
  short s;
  char c;
  int i;
};

int
main(int argc, char *argv[])
{
  struct data_naive n = {
    .s = 0,
    .i = 0,
    .c = 0
  };

  struct data_align a = {
    .s = 0,
    .i = 0,
    .c = 0
  };

  printf("sizeof(struct data_naive)=%zd\n", sizeof(n));
  printf("sizeof(struct data_align)=%zd\n", sizeof(a));

  exit(EXIT_SUCCESS);
}
