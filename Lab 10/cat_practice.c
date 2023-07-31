#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    char temp[100];
    if (argc < 2)
    {
        printf("Parameter has to be passed\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("\nThe file does not exist.\n");
        exit(1);
    }

    while (!feof(fp))
    {
        fgets(temp, 100, fp);
        printf("%s", temp);
    }
    fclose(fp);
}