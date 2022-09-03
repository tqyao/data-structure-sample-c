#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a = ')';
    int b = a;
    printf("b = %d\n", b);
    char c = b;
    printf("c = %c\n", c);

    printf("c == b => %d\n", c == b);
    // printf("c == b => %d\n", c == b);

    printf("-->\n");
    char *p = "()[]{}";
    while (*p)
    {
        printf("%d ", *(p++));
    }
    printf("\n");

    return 1;
}
