#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
// #include <sys/types.h>

void main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc < 2)
    {
        printf("\nThe directory name is not being passed.\n");
        return;
    }

    if ((dp = opendir(argv[1])) == NULL)
    {
        printf("The directory doesnt exist\n");
        return;
    }

    while ((dirp = readdir(dp)) != NULL)
    {
        printf("%s\n", dirp->d_name);
    }
    closedir(dp);
}