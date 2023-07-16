#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void main()
{
    char filename[20], pattern[25], temp[120];
    printf("Enter the filename: \n");
    scanf("%s", filename);
    printf("Enter the pattern: \n");
    scanf("%s", pattern);

    FILE *fp = fopen(filename, "r");
    while (!(feof(fp)))
    {
        fgets(temp, 100, fp);
        if (strstr(temp, pattern))
        {
            printf("%s", temp);
        }
    }
    fclose(fp);
}
