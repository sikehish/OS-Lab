#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>

sem_t wrt;
pthread_mutex_t mutex;
int cnt = 1, numreader = 0;

void *writer(void *pno)
{
    sem_wait(&wrt);
    // sem_wait(&sem_name); If the value of the semaphore is negative, the calling process blocks;
    cnt = cnt * 2;
    printf("Writer %d modified cnt to %d\n", (*((int *)pno)), cnt);
    sem_post(&wrt);
}

void *reader(void *cno)
{
    pthread_mutex_lock(&mutex);
    numreader++;
    if (numreader == 1)
        sem_wait(&wrt);
    pthread_mutex_unlock(&mutex);

    printf("Reader %d: Reading cnt as %d\n", (*((int *)cno)), cnt);

    pthread_mutex_lock(&mutex);
    numreader--;
    if (numreader == 0)
        sem_post(&wrt);
    pthread_mutex_unlock(&mutex);
}

void main()
{

    pthread_t pro[5], con[10];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt, 0, 1);

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++)
    {
        pthread_create(&con[i], NULL, reader, (void *)&a[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&pro[i], NULL, writer, (void *)&a[i]);
    }

    for (int i = 0; i < 10; i++)
        pthread_join(con[i], NULL);

    for (int i = 0; i < 5; i++)
        pthread_join(pro[i], NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);
}