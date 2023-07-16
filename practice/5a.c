#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void main()
{

    int fd = open("sample.txt", O_RDWR);
    int n;
    char buffer[50];

    printf("File descriptor is %d\n", fd);
    if (fd == -1)
    {
        printf("Failed to open file.\n");
        exit(0);
    }

    printf("Reading first 10 characters\n");
    n = read(fd, buffer, 10);
    write(1, buffer, n);
    printf("\n");

    printf("Skipping first 5 characters from current position\n");
    lseek(fd, 5, SEEK_CUR);
    n = read(fd, buffer, 10);
    write(1, buffer, n);
    printf("\n");

    printf("Going to 5th last character\n");
    lseek(fd, -5, SEEK_END);
    n = read(fd, buffer, 5);
    write(1, buffer, n);
    printf("\n");

    printf("Going to 3rd character in the file\n");
    lseek(fd, 3, SEEK_SET);
    n = read(fd, buffer, 5);
    write(1, buffer, n);
    printf("\n");
}