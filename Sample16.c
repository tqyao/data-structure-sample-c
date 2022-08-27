#include <stdio.h>
#include <stdlib.h>

void test();
void test()
{
    if (1)
    {
        printf("dfg\n");
        return;
    }
    printf("abc\n");
}

int main()
{
    test();
    return 0;
}