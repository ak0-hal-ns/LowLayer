/* Prints glibc version.

    __GLIBC__ and __GLIBC_MINOR__ (since ver2.0)

    <gnu/libc-version.h>
    const char *gnu_get_libc_version(void);

    <unistd.h>
    size_t confstr(int name, char *buf, size_t len);
    _CS_GNU_LIBC_VERSION

*/


#include <gnu/libc-version.h>
#include <unistd.h>
#include <stdio.h>    /* printf */
#include <stdlib.h>    /* malloc, abort */

int
main(int argc, char *argv[])
{
    char *buf;
    size_t n;

    printf("glibc %d.%d\n", __GLIBC__, __GLIBC_MINOR__);

    printf("glibc %s\n", gnu_get_libc_version());

    /* confstr - LIBC VER */
    n = confstr(_CS_GNU_LIBC_VERSION, NULL, (size_t) 0);
    buf = malloc(n);
    if (buf == NULL)
        abort();
    confstr(_CS_GNU_LIBC_VERSION, buf, n);
    printf("%s\n", buf);

    /* confstr - LIBPTHREAD VER */
    n = confstr(_CS_GNU_LIBPTHREAD_VERSION, NULL, (size_t) 0);
    buf = malloc(n);
    if (buf == NULL)
        abort();
    confstr(_CS_GNU_LIBPTHREAD_VERSION, buf, n);
    printf("GNU lib-pthread: %s\n", buf);

    /* confstr - PATH */
    n = confstr(_CS_PATH, NULL, (size_t) 0);
    buf = malloc(n);
    if (buf == NULL)
        abort();
    confstr(_CS_PATH, buf, n);
    printf("PATH for POSIX.2 std-util: %s\n", buf);

    return 0;
}
