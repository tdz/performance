
#include <stdlib.h>
#include "sort.h"

static void
swap(int *a, int *b)
{
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

struct range {
  size_t off;
  size_t len;
};

long long
sort(int *data, size_t len)
{
  long long nsteps = 0;

  struct range *s = malloc(sizeof(*s));

  if (!s) {
    perror("malloc");
    goto err_malloc;
  }

  size_t siz = 1;

  size_t top = 0;

  s[top].off = 0;
  s[top].len = len;
  ++top;

  long long iter = 0;

  while (top) {
    --top;

    size_t off = s[top].off;
    size_t len = s[top].len;
    size_t pivot = off + len / 2;

    size_t i;

    for (i = off; i < pivot; ++i) {
      if (data[i] < data[pivot])
        swap(data+i, data+pivot);
      ++nsteps;
    }

    size_t end = off+len;

    for (i = pivot+1; i < end; ++i) {
      if (data[pivot] < data[i])
        swap(data+pivot, data+i);
      ++nsteps;
    }

    if ((top+2) > siz) {
      siz *= 2;
      void *mem = realloc(s, siz*sizeof(*s));
      if (!mem) {
        perror("realloc");
        goto err_realloc;
      }
      s = mem;
    }

    if (pivot > off) {
      s[top].off = off;
      s[top].len = pivot-1-off;
      ++top;
    }

    if (pivot < end) {
      s[top].off = pivot+1;
      s[top].len = end-s[top].off;
      ++top;
    }
  }

  free(s);

  return nsteps;

err_realloc:
  free(s);
err_malloc:
  return -1;
}
