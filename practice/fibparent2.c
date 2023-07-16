#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/shm.h>

int main(int argc, char *argv[])
{
    int i;
    if (argc > 1)
    {
        sscanf(argv[1], "%d", &i);
        if (i < 1)
        {
            printf("Not a valid argument\n");
            return 0;
        }
    }
    else
    {
        printf("No arguments provided\n");
        return 0;
    }

    pid_t pid = fork();

    if (pid == 0)
    {
        execlp("./fib", "fib", argv[1], NULL);
    }
    if (pid > 0)
    {
        wait(NULL);
        printf("\n[PARENT] Child process completed\n");
        int shmfd = shm_open("OS", O_RDONLY, 0666);
        void *shmptr = mmap(0, 4096, PROT_READ, MAP_SHARED, shmfd, 0);
        printf("\nParent printing:\n");
        printf("%s\n", (char *)shmptr);
        shm_unlink("OS");
    }
}
