#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void main(int argc, char *argv[])
{

    struct dirent *dirp;
    DIR *dp;

    if (argc < 2)
    {
        printf("Required parameters not passed!\n");
        return;
    }

    if ((dp = opendir(argv[1])) == NULL)
    {
        printf("The directory doesn't exist\n");
        return;
    }

    while ((dirp = readdir(dp)) != NULL)
    {
        printf("%s\n", dirp->d_name);
    }
    closedir(dp);
}