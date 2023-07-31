#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void main(int argc, char *argv[])
{

    int fd = open("sample.txt", O_RDONLY);
    int n;
    char buffer[50];

    if (fd == -1)
    {
        printf("File doesnt exist\n");
        return;
    }

    printf("Reading first 10 characters from file\n");
    n = read(fd, buffer, 10);
    write(1, buffer, n);

    printf("\nSkipping 5 characters from current position in the file\n");
    lseek(fd, 5, SEEK_CUR);
    n = read(fd, buffer, 10);
    write(1, buffer, n);

    printf("\nGoing to 5th last character in the file\n");
    lseek(fd, -5, SEEK_END);
    n = read(fd, buffer, 5);
    write(1, buffer, n);

    printf("\nGoing to the 3rd character in the file\n");
    lseek(fd, 3, SEEK_SET);
    n = read(fd, buffer, 5);
    write(1, buffer, n);
    printf("\n");
}