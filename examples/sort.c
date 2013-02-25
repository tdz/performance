
#include <stdio.h>
#include <stdlib.h>
#include "readrand.h"
#include "sort.h"

int
main(int argc, char *argv[])
{
  static const size_t len = 1024 *1024;

  int *data = readrand(len*sizeof(*data));

  if (!data)
      goto err_readrand;

  long long nsteps = sort(data, len);

  if (nsteps < 0)
    goto err_sort;

  printf("%lld steps\n", nsteps);

  free(data);

  exit(EXIT_SUCCESS);

err_sort:
  free(data);
err_readrand:
  exit(EXIT_FAILURE);
}
