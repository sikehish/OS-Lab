/*
11a Write a program with two threads and a main thread. Schedule the task of
calculating the natural sum upto ‘n’ terms and factorial of ‘n’ on these threads.
Note: The main thread should read ‘n’ from command line and pass it as parameter
to remaining threads. Terminate the threads using system calls.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *sum(void *arg);
void *mul(void *arg);
long int sm = 0, prod = 1;
void main(int argc, char *argv[])
{
    pthread_t T1, T2;
    pthread_attr_t attr;      // set of thread attributes
    pthread_attr_init(&attr); // get the default attributes
    pthread_create(&T1, &attr, sum, argv[1]);
    pthread_create(&T2, &attr, mul, argv[1]);
    pthread_join(T1, NULL);
    pthread_join(T2, NULL);
    printf("Inside main thread\n");
    printf("sum=%ld\n", sm);
    printf("product=%ld\n", prod);
}
void *sum(void *parm)
{
    int i, n;
    n = atoi(parm); // string to integer i.e., ASCII to int
    printf("inside  sum thread\n");

    for (i = 1; i <= n; i++)
    {
        sm += i;
    }
    printf("sum thread completed\n");
}
void *mul(void *parm)
{
    int i, n;
    n = atoi(parm);
    printf("inside mul thread\n");
    for (i = 2; i <= n; i++)
    {
        prod = prod * i;
    }
    printf("mul thread completed  product\n");
}