#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int cnt = 1, numreader = 0;
sem_t wrt;
pthread_mutex_t mutex;

void *reader(void *rno);
void *writer(void *wno);

void *reader(void *rno)
{

    pthread_mutex_lock(&mutex);
    numreader++;
    if (numreader == 1)
        sem_wait(&wrt);
    pthread_mutex_unlock(&mutex);

    printf("Reader %d: read cnt as %d\n", *((int *)rno), cnt);

    pthread_mutex_lock(&mutex);
    numreader--;
    if (numreader == 0)
        sem_post(&wrt);
    pthread_mutex_unlock(&mutex);
}

void *writer(void *wno)
{
    sem_wait(&wrt);
    cnt *= 2;
    printf("Writer %d: Writer changed to %d\n", *((int *)wno), cnt);
    sem_post(&wrt);
}

void main()
{
    pthread_t readers[10], writers[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt, 0, 1);

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++)
        pthread_create(&readers[i], NULL, reader, (void *)&(arr[i]));
    for (int i = 0; i < 5; i++)
        pthread_create(&writers[i], NULL, writer, (void *)&(arr[i]));

    for (int i = 0; i < 10; i++)
        pthread_join(readers[i], NULL);
    for (int i = 0; i < 5; i++)
        pthread_join(writers[i], NULL);

    sem_destroy(&wrt);
    pthread_mutex_destroy(&mutex);
}