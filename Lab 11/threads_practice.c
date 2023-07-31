#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *sum(void *);
void *fact(void *);
int sm = 0, ft = 1;

void main(int argc, char *argv[])
{
    pthread_t T1, T2;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&T1, &attr, sum, argv[1]);
    pthread_create(&T2, &attr, fact, argv[1]);
    pthread_join(T1, NULL);
    pthread_join(T2, NULL);
    printf("Inside main thread\n");
    printf("Sum=%d\n", sm);
    printf("Fact=%d\n", ft);
    printf("Main thread completed\n");
}

void *sum(void *s)
{
    int j = atoi(s);
    printf("Inside sum thread\n");
    for (int i = 1; i <= j; i++)
        sm += i;
    printf("Sum thread completed\n");
}

void *fact(void *s)
{
    int j = atoi(s);
    printf("Inside factorial thread\n");
    for (int i = 2; i <= j; i++)
        ft *= i;
    printf("Factorial thread completed\n");
}