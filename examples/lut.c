
#include <stdlib.h>
#include "readrand.h"
#include "lut.h"

int
main(int argc, char *argv[])
{
  static const size_t siz = 16 * 1024 *1024;

  unsigned char *data = readrand(siz*sizeof(*data));

  if (!data)
      goto err_readrand;

  const unsigned char *beg = data;
  const unsigned char *end = data+siz;

  while (beg < end) {
    lut(*beg);
    ++beg;
  }

  free(data);

  exit(EXIT_SUCCESS);

err_readrand:
  exit(EXIT_FAILURE);
}
