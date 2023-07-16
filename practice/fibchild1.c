#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    int shmid = shmget((key_t)1122, 4096, 0666);
    void *shmptr = shmat(shmid, NULL, 0666);
    int num = atoi(argv[1]);
    int n1 = 0;
    int n2 = 1;
    int n3 = n1 + n2;
    printf("Child printing:\n");
    printf("The fib pattern: ");
    for (int i = 0; i < num; i++)
    {
        sprintf(shmptr, "%d", n1);
        shmptr += strlen(shmptr);
        printf("%d ", n1);
        n1 = n2;
        n2 = n3;
        n3 = n1 + n2;
    }

    shmctl(shmid, IPC_RMID, NULL);
}