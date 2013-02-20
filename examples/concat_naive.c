
#include <stdlib.h>
#include <string.h>
#include "concat.h"

char *
concat(const char *str1, const char *str2, char *oldstr, size_t *oldsiz)
{
  size_t len1 = strlen(str1);
  size_t len2 = strlen(str2);
  size_t siz = len1+len2+1;

  free(oldstr);

  char *str = malloc(siz);

  if (!str)
    abort();

  *oldsiz = siz;

  char *pos = str;

  memcpy(pos, str1, len1);
  pos += len1;
  memcpy(pos, str2, len2+1);

  return str;
}
