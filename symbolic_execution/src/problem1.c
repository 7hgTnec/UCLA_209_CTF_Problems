#include <stdio.h>
#include <string.h>

int main()
{
    char s[10];
    char psw[10] = "PWD_P1";

    printf("Please input the password:\n");
    scanf("%s", s);

    if (strcmp(s, psw) == 0)
    {
        printf("flag{87ead147bfcde35f4673e8a18d43269c26a2ddfa}\n");
    }
    else
    {
        printf("Try again\n");
    }

    return 0;
}
