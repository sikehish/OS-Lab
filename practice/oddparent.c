#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int i;
    int shmid = shmget((key_t)1122, 4096, 0666 | IPC_CREAT);
    void *shmptr = shmat(shmid, NULL, 0666);

    if (argc > 1)
    {
        sscanf(argv[1], "%d", &i);
    }
    else
    {
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0)
    {
        execlp("./odd", "odd", argv[1], NULL);
    }

    if (pid > 0)
    {
        wait(NULL);
        printf("Printing in PARENT\n");
        printf("Printing data...\n");
        printf("%s\n", (char *)shmptr);
        shmdt(shmptr);
    }
}