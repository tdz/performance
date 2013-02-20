
#include <stdlib.h>
#include "readrand.h"
#include "concat.h"

int
main(int argc, char *argv[])
{
  static const size_t siz = 2ul * 1024ul * 1024ul *1024ul;

  char *data = readrand(siz);

  if (!data)
      goto err_readrand;

  unsigned char *beg = data;
  const unsigned char *end = data+siz;

  size_t strsiz = 0;
  char *str = NULL;

  while (beg < end) {

    size_t len1 = *beg;

    if ((beg+len1+2) >= end)
      break;

    const char *str1 = (const char*)beg;
    beg += len1;
    *beg = '\0';
    ++beg;

    size_t len2 = *beg;

    if ((beg+len2+1) >= end)
      break;

    const char *str2 = (const char *)beg;
    beg += len2;
    *beg = '\0';
    ++beg;

    str = concat(str1, str2, str, &strsiz);
  }

  free(str);
  free(data);

  exit(EXIT_SUCCESS);

err_readrand:
  exit(EXIT_FAILURE);
}
