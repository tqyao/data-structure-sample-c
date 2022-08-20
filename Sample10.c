#include <stdio.h>
#include <stdlib.h>
void test(int *param)
{
    *param = 1;
    // printf("%d\n", param);
}
void func1(int *a)
{
    // a为形参
    *a = 4; //使用解引用符号，修改函数外面的值。
    a = 0;  //将a指针保存的地址值从b的地址变成了0，实际参数没有任何改变。
}

int main02()
{
    int b = 0;
    int *c = &b;
    func1(c); // b为实参
    return 0;
}

int main01()
{
    int *p; //声明指针未赋值，野指针，c语言禁止对野指针赋值
    // *p = 1;
    printf("%d\n", *p); // 野指针可以访问
    // test(p);

    p = (int *)malloc(sizeof(int));
    *p = 1;
    printf("%d", *p);
    return 0;
}

void test03(int *p)
{
    // *p = 1;
    printf("%d\n", *p);
}
int main()
{
    int *p;
    test03(p);
    return 0;
}