
#include <stddef.h>
#include "sort.h"

static void
swap(int *a, int *b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

long long
sort(int *data, size_t len)
{
  long long nsteps = 0;

  size_t i, j;

  for (i = 0; i < len; ++i)
    for (j = i+1; j < len; ++j) {
      if (data[i] > data[j])
        swap(data+i, data+j);
      ++nsteps;
    }

  return nsteps;
}
