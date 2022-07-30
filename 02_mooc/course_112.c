#include <stdio.h>

/**
 * 打印1~N
 * @brief
 *
 * @return int
 */
void printfN01(int n);
void printfN02(int n);
int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;
    // printfN01(n);
    printfN02(n);
    return 0;
}

void printfN01(int n)
{
    for (int i = 1; i <= n; i++)
        printf("%d\n", i);
}

void printfN02(int n)
{
    // if (n > 1)
    //     printfN02(n - 1);
    // printf("%d\n", n);
    // return;

    if (!n)
        return;
    printfN02(n - 1);
    printf("%d\n", n);
    return;
}