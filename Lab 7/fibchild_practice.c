#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void main(int argc, char *argv[])
{
    int shmid = shmget((key_t)1122, 4096, 0666);
    void *shmptr = shmat(shmid, NULL, 0666);
    printf("\nChild printing\n");
    int n = atoi(argv[1]);
    int n1 = 0, n2 = 1, n3 = 1;
    for (int i = 0; i < n; i++)
    {
        n3 = n1 + n2;
        printf("%d ", n1);
        sprintf(shmptr, "%d ", n1);
        shmptr += (strlen(shmptr));
    }
    shmctl(shmid, IPC_RMID, NULL);
}