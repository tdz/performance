
#include "sgn.h"

int
sgn(int i)
{
  if (i > 0)
    return 1;
  else if (i < 0)
    return -1;

  return 0;
}
