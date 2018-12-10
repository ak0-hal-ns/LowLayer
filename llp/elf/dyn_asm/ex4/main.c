#include <stdio.h>

extern int sofun(void);
extern const char sostr [];  // buffer, not pointer

int
main(int argc, char* argv[])
{
    printf("%d\n", sofun());
    puts(sostr);

    return 0;
}
