/* Sample of Error handling.

definitions of O_*:
  <bits/fcntl-linux.h> from <bits/fcntl.h> from <fcntl.h>

<stdio.h>
void perror(const char *s);

<string.h>
char *strerror(int errnum);  // non-reentrant
 int *strerror_r(int errnum, char *buf, size_t buflen);  // XSI-compliant
char *strerror_r(int errnum, char *buf, size_t buflen);  // GNU-specific

*/

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>    /* O_RDONLY */
#include <stdlib.h>    /* exit, EXIT_FAILURE, EXIT_SUCCESS */

int
main(int argc, char *argv[])
{
    int fd, flags, n;
    char buf[1024], *bufp;
    size_t buflen;

    flags = O_RDONLY;
    buflen = 1024;

    /* perror */
    fd = open("FILENAME_NOT_EXIST", flags);
    if (fd == -1) {
        perror("[perror] open");    /* open: No such file or directory */
    }

    /* strerror */
    fd = open("FILENAME_NOT_EXIST", flags);
    if (fd == -1) {
        bufp = strerror(errno);
        printf("[strerror] open: %s\n", bufp);
    }

    /* strerror_r for multi-thread */
    bufp = (char *) &buf;

    fd = open("FILENAME_NOT_EXIST", flags);
    if (fd == -1) {
#if _POSIX_C_SOURCE >= 200112L && !_GNU_SOURCE
        n = strerror_r(errno, bufp, buflen);
        if (n == 0)
            printf("[strerror_r :XSI] open: %s\n", bufp);
        else
            perror("strerror_r");
#else
        bufp = strerror_r(errno, bufp, buflen);
        printf("[strerror_r :GNU] open: %s\n", bufp);
#endif
    }

    exit(EXIT_SUCCESS);
}
