
#include <stdlib.h>
#include <string.h>
#include "concat.h"

char *
concat(const char *str1, const char *str2, char *oldstr, size_t *oldsiz)
{
  size_t len1 = strlen(str1);
  size_t len2 = strlen(str2);
  size_t siz = len1+len2+1;

  char *str;

  if (siz <= *oldsiz) {
    str = oldstr;
  } else {
    str = realloc(oldstr, siz);

    if (!str)
      abort();

    *oldsiz = siz;
  }

  char *pos = str;

  strcpy(pos, str1);
  pos += len1;
  strcpy(pos, str2);

  return str;
}
