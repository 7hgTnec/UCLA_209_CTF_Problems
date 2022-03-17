#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
  printf("target file execuated\n Please input something:");
  int result = -1;
  char userInput[20] = "";

  gets(userInput);

  if(result == 0x616161BUFFER_P0){
    printf("flag{b29218d6d2ef31d5448f2c22111778319f620c38}\n");
  }

  return 0;
}
