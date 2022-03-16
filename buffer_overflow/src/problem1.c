#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fun1(char *argv[])
{
    char buf[BUFFER_P1];
    strcpy(buf, argv[1]);
    return 0;
}

int main(int argc, char *argv[])
{
    printf("target file execuated\n");
    if (argc != 2)
    {
        printf("requires argc equal to 2\n");
        exit(-1);
    }
    fun1(argv);
    return 0;
}
