#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define BufferSize 3
#define MaxItems 3

int in = 0, out = 0, buffer[BufferSize];
sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *pno);
void *consumer(void *cno);

void *producer(void *pno)
{
    int item;
    for (int i = 0; i < MaxItems; i++)
    {
        item = rand();
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("Producer %d: Item %d inserted at %d\n", *((int *)pno), item, in);
        in = (in + 1) % BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *cno)
{
    for (int i = 0; i < MaxItems; i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("Consumer %d: Item %d removed at %d\n", *((int *)cno), item, out);
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

    int arr[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++)
        pthread_create(&pro[i], NULL, producer, (void *)&arr[i]);
    for (int i = 0; i < 3; i++)
        pthread_create(&con[i], NULL, consumer, (void *)&arr[i]);

    for (int i = 0; i < 3; i++)
        pthread_join(pro[i], NULL);
    for (int i = 0; i < 3; i++)
        pthread_join(con[i], NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
}