#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int key = 7;

char encodeFun(char s)
{
    if('a'> s || s > 'z')
    {
        printf("Try again\n");
        exit(1);
    }
    return 'a' + ((s + key)%26);
}

int main()
{
    char s[10];
    char psw[10] = "PWD_P2";

    printf("Please input the password:\n");
    scanf("%s", s);

    for (int i = 0; i<strlen(s); i++)
    {
        s[i] = encodeFun(s[i]);
        key ++;
    }

    if (strcmp(s, psw) == 0)
    {
        printf("flag{7db91bdb9c3d06c8f50146e37015fed3db15cdfc}\n");
    }
    else
    {
        printf("Try again\n");
    }

    return 0;
}
