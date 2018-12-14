#ifndef _ERROR_FUNCTIONS_H
#define _ERROR_FUNCTIONS_H

#include <stdint.h>
#include <stdnoreturn.h>

void err_msg(const char *format, ...);

noreturn void
err_exit3(const char *format, ...);

noreturn void
err_exit2(const char *format, ...);

noreturn void
err_exit_EN(int32_t errnum, const char *format, ...);

noreturn void
fatal(const char *format, ...);

noreturn void
usage_err(const char *format, ...);

noreturn void
cmdline_err(const char *format, ...);

#endif
