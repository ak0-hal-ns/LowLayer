/*
 *    gcc -O3 -pthread create_mwe.c
 *
 *    int
 *    pthread_create(
 *        pthread_t * thread,
 *        const pthread_attr_t * attr,
 *        void * (*start_routine) (void *),
 *        void * arg
 *    );
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *
threadimpl(void * arg)
{
    for (int i = 0; i < 10; i++) {
        puts(arg);
        sleep(1);
    }

    return NULL;
}

int
main(int argc, char * argv[])
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, threadimpl, "fizz");
    pthread_create(&t2, NULL, threadimpl, "buzzzz");
    pthread_exit(NULL);
    puts("bye");

    return 0;
}
