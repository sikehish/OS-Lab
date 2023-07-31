#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    char pattern[10], filename[25], temp[100];

    printf("Enter the filename\n");
    scanf("%s", filename);
    printf("Enter the pattern\n");
    scanf("%s", pattern);

    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("File doesnt exist\n");
        return;
    }

    while (!feof(fp))
    {
        fgets(temp, 100, fp);
        if (strstr(temp, pattern))
        {
            printf("%s", temp);
        }
    }
    fclose(fp);
}