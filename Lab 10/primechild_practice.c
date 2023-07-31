#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

void main(int argc, char *argv[])
{

    int shm_fd = shm_open("OS", O_RDWR | O_CREAT, 0666);
    ftruncate(shm_fd, 4096);
    void *shmptr = mmap(0, 4096, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    printf("\nChild Printing:\n");

    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    for (int i = m; i <= n; i++)
    {
        int flag = 0;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            printf("%d ", i);
            sprintf(shmptr, "%d ", i);
            shmptr += (strlen(shmptr));
        }
    }
}