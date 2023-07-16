/*************************************************************************************************************************
 * Program to stimulate the cat command of linux operating system.
 * cat command prints out the contents of the given file to the console, without opening a editor.
 * This command can be used to easily display the contents of the required file, without opening.
 * FILE is an object type suitable for storing information for a file stream.
 * fgetc() gets the next character and from the specified stream and advances the position indicator for the stream.
 * Prototype: int fgetc(FILE *stream)
 * EOF denotes End Of File.
 * The file name is to be passed as command line argument.
 *************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;
    char temp[50];

    // Optional
    if (argc < 2)
    {
        printf("\nThe file name is not passed\n");
        exit(1);
    }

    fp = fopen(argv[1], "r");

    // Optional
    if (fp == NULL)
    {
        printf("\nThe file does not exist.\n");
        exit(1);
    }

    while (!feof(fp))
    {
        fgets(temp, 50, fp);
        printf("%s", temp);
    }
    fclose(fp);
    return 0;