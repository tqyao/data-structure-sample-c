#include <stdio.h>

// void test01(int &x);
int test02(int *x);
int main()
{
    int x = 1;
    // test01(x);
    // printf("test01 =>%d\n", x);

    int *p = &x;
    // test02(p);
    test02(&x);
    printf("test02 =>%d\n", x);
}
// void test01(int &x)
// {
//     *x = 1024;
// }
int test02(int *x)
{
    *x = 1024;
    return 0;
}