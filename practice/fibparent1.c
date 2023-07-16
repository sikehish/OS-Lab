#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int i;
    int shmid = shmget((key_t)1122, 4096, 0666 | IPC_CREAT);
    void *shmptr = shmat(shmid, NULL, 0666);

    if (argc < 2)
    {
        printf("Arguments missing\n");
        return 1;
    }
    else
    {
        sscanf(argv[1], "%d", &i);
        if (i < 1)
        {
            printf("Not possible\n");
            return 1;
        }
    }

    pid_t child_pid = fork();
    if (child_pid == 0)
    {
        printf("Inside child proceess\n");
        execlp("./fib", "fib", argv[1], NULL);
    }
    else
    {
        wait(NULL);
        printf("\n[PARENT] Child completed\n");
        printf("\nParent printing:\n");
        printf("%s\n", (char *)shmptr);
        shmdt(shmptr);
    }

    return 0;
}