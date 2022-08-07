#include <stdio.h>

int main()
{
    int arr[100] = {0};
    int *p = arr;
    while (*p)
        printf("%d\n", *(p++));
}