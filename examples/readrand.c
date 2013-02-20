
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "readrand.h"

void *
readrand(size_t siz)
{
  void *buf = malloc(siz);

  if (!buf) {
    perror("malloc");
    goto err_malloc;
  }

  int fd = TEMP_FAILURE_RETRY(open("./random.data", O_RDONLY));

  if (fd < 0) {
    perror("open");
    goto err_open;
  }

  char *pos = buf;

  while (siz) {
    ssize_t res = TEMP_FAILURE_RETRY(read(fd, pos, siz));

    if (res < 0) {
      perror("read");
      goto err_read;
    } else if (res == 0) {
      break;
    }

    siz -= res;
    pos += res;
  }

  TEMP_FAILURE_RETRY(close(fd));

  return buf;

err_read:
  TEMP_FAILURE_RETRY(close(fd));
err_open:
  free(buf);
err_malloc:
  return NULL;
}
