#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct myStruct {
  int arr[STRUCT_BYNS_P2];
};

int fun1(char *sptr, int count)
{
  struct myStruct buf[MAX_STRUCT_P2];

  if (count < MAX_STRUCT_P2)
    memcpy(buf, sptr, count * sizeof(struct myStruct));

  return 0;
}

int main(int argc, char *argv[])
{
  int count;
  char *buf_ptr;
  printf("target file execuated\n");
  if (argc != 2)
    {
      printf("requires argc equal to 2\n");
      exit(-1);
    }

  sscanf(argv[1], "%d,", &count);
  
  buf_ptr = argv[1];

  while (*buf_ptr != ',')
    {
      buf_ptr++;
    }
  buf_ptr++;
  //printf("%d\n", count);
  fun1(buf_ptr, count);

  return 0;
}
