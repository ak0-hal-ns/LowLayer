/* Error handling functions

  $ gcc -o liberr.a -std=c11 -pedantic-errors -Wall -Werror \
        -c error_functions.c
*/

#include <errno.h>      /* errno */
#include <string.h>     /* strerror */
#include <stdbool.h>    /* bool, true, false */
#include <stdlib.h>     /* exit, EXIT_FAILURE, getenv, abort */
#include <unistd.h>     /* _exit */
#include <stdarg.h>     /* va_start, va_end */
#include <stdio.h>      /* stdout, stderr, fflush,
                           fprintf, vfprintf, snprintf, vsnprintf */

#include "error_functions.h"  /* <stdint.h> <stdnoreturn.h> */
#include "err_names.c.inc"    /* MAX_ENAME, ename[] */


static noreturn void terminate(bool use_exit3);
static void output_error(bool use_err, int32_t err, bool flush_stdout,
                         const char *format, va_list ap);

const uint32_t BUF_SIZE = 1024;  /* used in output_error() */


void
err_msg(const char *format, ...)
{
    va_list arg_list;
    int32_t saved_errno = errno;  /* In case we change it here */

    va_start(arg_list, format);
    output_error(true, errno, true, format, arg_list);
    va_end(arg_list);

    errno = saved_errno;
}


void
err_exit3(const char *format, ...)
{
    va_list arg_list;

    va_start(arg_list, format);
    output_error(true, errno, true, format, arg_list);
    va_end(arg_list);

    terminate(true);
}


void
err_exit2(const char *format, ...)
{
    va_list arg_list;

    va_start(arg_list, format);
    output_error(true, errno, false, format, arg_list);
    va_end(arg_list);

    terminate(false);
}


void
err_exit_EN(int32_t errnum, const char *format, ...)
{
    va_list arg_list;

    va_start(arg_list, format);
    output_error(true, errnum, true, format, arg_list);
    va_end(arg_list);

    terminate(true);
}


void
fatal(const char *format, ...)
{
    va_list arg_list;

    va_start(arg_list, format);
    output_error(false, 0, true, format, arg_list);
    va_end(arg_list);

    terminate(true);
}


void
usage_err(const char *format, ...)
{
    va_list arg_list;

    fflush(stdout);  /* Flush any pending stdout */

    fprintf(stderr, "Usage: ");
    va_start(arg_list, format);
    vfprintf(stderr, format, arg_list);
    va_end(arg_list);

    fflush(stderr);  /* In case stderr is not line-buffered */
    exit(EXIT_FAILURE);
}


void
cmdline_err(const char *format, ...)
{
    va_list arg_list;

    fflush(stdout);  /* Flush any pending stdout */

    fprintf(stderr, "Command-line usage:");
    va_start(arg_list, format);
    vfprintf(stderr, format, arg_list);
    va_end(arg_list);

    fflush(stderr);  /* In case stderr is not line-buffered */
    exit(EXIT_FAILURE);
}


/* Dump core if EF_DUMPCORE environment variable is defined and
   is a nonempty string; otherwise call exit (3) or _exit (2), 
   depending on the value of 'use_exit3'. */
static noreturn
void
terminate(bool use_exit3)
{
    char *s = getenv("EF_DUMPCORE");
    if (s != NULL && *s != '\0')
        abort();
    else if (use_exit3)
        exit(EXIT_FAILURE);
    else
        _exit(EXIT_FAILURE);
}


static
void
output_error(bool use_err, int32_t err, bool flush_stdout,
             const char *format, va_list ap)
{
    char user_msg[BUF_SIZE];
    char err_text[BUF_SIZE];
    char buf[BUF_SIZE * 2];

    vsnprintf(user_msg, BUF_SIZE, format, ap);

    if (use_err)
        snprintf(err_text, BUF_SIZE, " [%s %s]",
                 (err > 0 && err <= MAX_ENAME) ?
                 ename[err] : "UNKNOWN", strerror(err));
    else
        snprintf(err_text, BUF_SIZE, "-");

    snprintf(buf, BUF_SIZE * 2, "ERROR%s %s\n", err_text, user_msg);

    if (flush_stdout)
        fflush(stdout);  /* Flush any pending stdout */

    fputs(buf, stderr);
    fflush(stderr);
}
