/* Feature Test Macros

   $ gcc ftm.c
   $ ./a.out
   [OBSOLETE] _POSIX_SOURCE defined, equivalent to _POSIX_C_SOURCE=1
   _POSIX_C_SOURCE defined: 200809L
   _DEFAULT_SOURCE defined
   _ATFILE_SOURCE defined$ gcc -D_ISOC99_SOURCE ftm.c

   $ gcc -ansi ftm.c
   $ ./a.out
   __STRICT_ANSI__ defined by -std=c99 or -ansi

   $ gcc -std=c99 ftm.c
   $ ./a.out
   __STRICT_ANSI__ defined by -std=c99 or -ansi

   $ gcc -std=c11 ftm.c
   $ ./a.out
   __STRICT_ANSI__ defined by -std=c99 or -ansi

   $ gcc -D_ISO99_SOURCE ftm.c
   $ ./a.out
   _ISOC99_SOURCE defined by this macro or -std=c99
   [OBSOLETE] _POSIX_SOURCE defined, equivalent to _POSIX_C_SOURCE=1
   _POSIX_C_SOURCE defined: 200809L
   _ATFILE_SOURCE defined

   $ gcc -D_ISOC11_SOURCE ftm.c
   $ ./a.out
   _ISOC11_SOURCE defined by this macro or -std=c11
   [OBSOLETE] _POSIX_SOURCE defined, equivalent to _POSIX_C_SOURCE=1
   _POSIX_C_SOURCE defined: 200809L
   _DEFAULT_SOURCE defined
   _ATFILE_SOURCE defined

   $ gcc -D_POSIX_C_SOURCE=200809L ftm.c
   $ ./a.out
   _POSIX_C_SOURCE defined: 200809L
   _ATFILE_SOURCE defined

   $ gcc -D_XOPEN_SOURCE=700 ftm.c
   $ ./a.out
   [OBSOLETE] _POSIX_SOURCE defined, equivalent to _POSIX_C_SOURCE=1
   _POSIX_C_SOURCE defined: 200809L
   _XOPEN_SOURCE defined: 700
   _ATFILE_SOURCE defined

   $ gcc -D_FILE_OFFSET_BITS=64 ftm.c
   $ ./a.out
   [OBSOLETE] _POSIX_SOURCE defined, equivalent to _POSIX_C_SOURCE=1
   _POSIX_C_SOURCE defined: 200809L
   _FILE_OFFSET_BITS defined: 64
   _DEFAULT_SOURCE defined
   _ATFILE_SOURCE defined

   $ gcc -D_DEFAULT_SOURCE ftm.c
   $ ./a.out
   [OBSOLETE] _POSIX_SOURCE defined, equivalent to _POSIX_C_SOURCE=1
   _POSIX_C_SOURCE defined: 200809L
   _DEFAULT_SOURCE defined
   _ATFILE_SOURCE defined

   $ gcc -D_GNU_SOURCE ftm.c
   $ ./a.out
   _ISOC99_SOURCE defined by this macro or -std=c99
   _ISOC11_SOURCE defined by this macro or -std=c11
   [OBSOLETE] _POSIX_SOURCE defined, equivalent to _POSIX_C_SOURCE=1
   _POSIX_C_SOURCE defined: 200809L
   _XOPEN_SOURCE defined: 700
   _XOPEN_SOURCE_EXTENDED defined
   _LARGEFILE64_SOURCE defined
   _DEFAULT_SOURCE defined
   _ATFILE_SOURCE defined
   _GNU_SOURCE defined

   $ gcc -D_THREAD_SAFE ftm.c
   $ ./a.out
   [OBSOLETE] _POSIX_SOURCE defined, equivalent to _POSIX_C_SOURCE=1
   _POSIX_C_SOURCE defined: 200809L
   _DEFAULT_SOURCE defined
   _ATFILE_SOURCE defined
   _THREAD_SAFE defined, synonim for the deprecated _REENTRANT

 */


#include <stdio.h>

int
main(int argc, char *argv[])
{
#ifdef __STRICT_ANSI__
    puts("__STRICT_ANSI__ defined by -std=c99 or -ansi");
#endif

#ifdef _ISOC99_SOURCE
    puts("_ISOC99_SOURCE defined by this macro or -std=c99");
#endif

#ifdef _ISOC11_SOURCE
    puts("_ISOC11_SOURCE defined by this macro or -std=c11");
#endif

#ifdef _POSIX_SOURCE
    puts("[OBSOLETE]"
         " _POSIX_SOURCE defined, equivalent to _POSIX_C_SOURCE=1");
#endif

    /* Commonly used for definitions from various versions of POSIX.1*/
#ifdef _POSIX_C_SOURCE
    printf("_POSIX_C_SOURCE defined: %ldL\n", (long) _POSIX_C_SOURCE);
#endif

    /* Commonly for definitions from various versions of SUS */
#ifdef _XOPEN_SOURCE
    printf("_XOPEN_SOURCE defined: %d\n", _XOPEN_SOURCE);
#endif

#ifdef _XOPEN_SOURCE_EXTENDED
    puts("_XOPEN_SOURCE_EXTENDED defined");
#endif

#ifdef _LARGEFILE64_SOURCE
    puts("_LARGEFILE64_SOURCE defined");
#endif

    /* In 64-bit system, this macro has no effect. */
#ifdef _FILE_OFFSET_BITS
    printf("_FILE_OFFSET_BITS defined: %d\n", _FILE_OFFSET_BITS);
#endif

#ifdef _BSD_SOURCE
    puts("[OBSOLETE]"
         " _BSD_SOURCE defined; Use _DEFAULT_SOURCE insteadly");
#endif

#ifdef _SVID_SOURCE
    puts("[OBSOLETE]"
         " _SVID_SOURCE defined; Use _DEFAULT_SOURCE insteadly");
#endif

    /* Commonly used 
       to get definitions that would normally be provided by default */
#ifdef _DEFAULT_SOURCE
    puts("_DEFAULT_SOURCE defined");
#endif

#ifdef _ATFILE_SOURCE
    puts("_ATFILE_SOURCE defined");
#endif

    /* Commonly used for GNU and/or Linux specific stuff */
#ifdef _GNU_SOURCE
    puts("_GNU_SOURCE defined");
#endif

#ifdef _REENTRANT
    puts("[OBSOLETE]"
         " _REENTRANT defined, equivalent to _POSIX_C_SOURCE>=199606L");
#endif

#ifdef _THREAD_SAFE
    puts("_THREAD_SAFE defined, synonim for the deprecated _REENTRANT");
#endif

#ifdef _FORTIFY_SOURCE
    puts("_FORTIFY_SOURCE defined");
#endif

}
