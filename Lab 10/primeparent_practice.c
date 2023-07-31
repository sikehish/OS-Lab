#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

void main(int argc, char *argv[])
{

    pid_t pid;

    if (argc > 2)
    {
        int m = atoi(argv[1]);
        int n = atoi(argv[2]);

        if (m < 1 || n < 1)
        {
            printf("\nWrong input given!!\n");
            return;
        }

        if (m > n)
        {
            char *el = argv[1];
            argv[1] = argv[2];
            argv[2] = el;
        }
    }
    else
    {
        printf("Pass parameters please\n");
        return;
    }

    pid = fork();

    if (pid == 0)
    {
        execlp("./prime", "prime", argv[1], argv[2], NULL);
    }
    else if (pid > 0)
    {
        wait(NULL);
        printf("\n[PARENT] Child process completed\n");
        printf("Parent printing\n");
        int shm_fd = shm_open("OS", O_RDONLY, 0666);
        void *shmptr = mmap(0, 4096, PROT_READ, MAP_SHARED, shm_fd, 0);
        printf("%s\n", (char *)shmptr);
        shm_unlink("OS");
    }
}