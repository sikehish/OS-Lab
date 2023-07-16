/*********************************************************************************************************
 * Child program to print prime numbers in given range using shm_open and mmap system calls.
 * Prototype of shm_open: int shm_open(const char *name, int oflag, mode_t mode);
 * shm_open() creates and opens a new, or opens an existing, POSIX shared memory object.
 * Protoype of mmap: void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
 * mmap() creates a new mapping in the virtual address space of the calling process.
 * The starting address for the new mapping is specified in addr.
 * Prototype of ftruncate:  int ftruncate(int fd, off_t length);
 * The ftruncate() functions cause the regular file named by path or referenced by fd to be truncated
   to a size of precisely length bytes.
 * Protoype of shm_unlink: int shm_unlink(const char *name);
 * The shm_unlink() function removes the object previously created by shm_open().
*********************************************************************************************************/
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
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    int shmfd = shm_open("OS", O_CREAT | O_RDWR, 0666);
    ftruncate(shmfd, 4096);
    void *shmptr = mmap(0, 4096, PROT_WRITE, MAP_SHARED, shmfd, 0);
    printf("\nChild Printing:\n");
    for (int i = a; i <= b; i++)
    {
        int flag = 1;
        for (int j = i / 2; j >= 2; j--)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf("%d ", i);
            sprintf(shmptr, "%d ", i);
            shmptr += (strlen(shmptr));
        }
    }
}