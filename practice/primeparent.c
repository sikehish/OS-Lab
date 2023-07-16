#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{

    int i, j;
    if (argc > 2)
    {
        sscanf(argv[1], "%d", &i);
        sscanf(argv[2], "%d", &j);
        if (i < 1 || j < 1)
        {
            printf("\nWrong input given!!\n");
            return 0;
        }
        else if (j > i)
        {
            int temp = i;
            i = j;
            j = temp;
        }
    }
    else
    {
        printf("Error: Arguments missing\n");
        return 0;
    }

    pid_t pid = fork();

    if (pid == 0)
    {
        execlp("./prime", "prime", argv[1], argv[2], NULL);
    }
    if (pid > 0)
    {
        wait(NULL);
        int shmfd = shm_open("OS", O_RDONLY, 0666);
        void *shmptr = mmap(0, 4096, PROT_READ, MAP_SHARED, shmfd, 0);
        printf("Child completed\n");
        printf("Parent printing:\n");
        printf("%s\n", (char *)shmptr);
        shm_unlink("OS");
    }
}
