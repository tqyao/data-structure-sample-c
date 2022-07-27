#include <stdio.h>
#include <math.h>
int main()
{
    char str[21];
    if (scanf("%s", str) != 1)
        return 0;

    char *p = str;
    while (*p)
    {
        printf("%c", *(p++));
    }
}