#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *sum(void *);
void *mul(void *);

int sm = 0, ml = 1;
void main(int argc, char *argv[])
{

    pthread_t T1, T2;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&T1, &attr, sum, argv[1]);
    pthread_create(&T2, &attr, mul, argv[1]);

    pthread_join(T1, NULL);
    pthread_join(T2, NULL);
    printf("Inside main thread\n");
    printf("sum: %d\n", sm);
    printf("factorial: %d\n", ml);
}

void *sum(void *i)
{
    printf("inside  sum thread\n");
    int ele = atoi(i);
    for (int j = 1; j <= ele; j++)
        sm += j;
    printf("Sum thread completed\n");
}

void *mul(void *i)
{
    printf("inside Factorial thread\n");
    int ele = atoi(i);
    for (int j = 1; j <= ele; j++)
        ml *= j;
    printf("Factorial thread completed\n");
}