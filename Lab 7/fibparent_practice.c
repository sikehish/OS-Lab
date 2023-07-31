#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

void main(int argc, char *argv[])
{

    int shmid = shmget((key_t)1122, 4096, 0666 | IPC_CREAT);
    void *shmptr = shmat(shmid, NULL, 0666);

    if (argc > 1)
    {
        int a = atoi(argv[1]);
        if (a < 1)
        {
            printf("Invalid inpit\n");
            return;
        }
    }
    else
    {
        printf("Please enter a command line argument!\n");
        return;
    }

    pid_t pid = fork();
    if (pid == 0)
    {
        execlp("./fib", "fib", argv[1], NULL);
    }
    else if (pid > 0)
    {
        wait(NULL);
        printf("\n[PARENT]Child process completed\n");
        printf("Parent printing...\n");
        printf("%s\n", (char *)shmptr);
        shmdt(shmptr);
    }
}