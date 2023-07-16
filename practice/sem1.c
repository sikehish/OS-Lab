#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>
#define BufferSize 3
#define MaxItems 3

int buffer[BufferSize];
int in = 0, out = 0;
sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *pno)
{
    int item;
    for (int i = 0; i < BufferSize; i++)
    {
        item = rand();
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("Producer %d: Inserted item %d at position %d\n", *((int *)pno), item, in);
        in = (in + 1) % BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *cno)
{
    for (int i = 0; i < BufferSize; i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("Producer %d: Removed item %d at position %d\n", *((int *)cno), item, out);
        out = (out + 1) % BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

void main()
{

    pthread_t pro[3], con[3];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BufferSize);
    sem_init(&full, 0, 0);

    int a[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++)
    {
        pthread_create(&pro[i], NULL, producer, (void *)&a[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        pthread_create(&con[i], NULL, consumer, (void *)&a[i]);
    }

    for (int i = 0; i < 3; i++)
        pthread_join(pro[i], NULL);
    for (int i = 0; i < 3; i++)
        pthread_join(con[i], NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
}