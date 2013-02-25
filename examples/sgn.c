
#include <stdlib.h>
#include "readrand.h"
#include "sgn.h"

int
main(int argc, char *argv[])
{
  static const size_t siz = 256 * 1024 * 1024;

  char *data = readrand(siz);

  if (!data)
      goto err_readrand;

  const char *beg = data;
  const char *end = data+siz;

  while (beg < end) {
    sgn(*beg);
    ++beg;
  }

  free(data);

  exit(EXIT_SUCCESS);

err_readrand:
  exit(EXIT_FAILURE);
}
