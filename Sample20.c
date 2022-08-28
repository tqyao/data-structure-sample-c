#include <stdio.h>
#include <stdlib.h>

int *test()
{
    int i = 1;
    printf("test i address => %p\n", &i);
    //返回函数内部的局部变量地址，是存储于栈中交给系统创建销毁的，当函数执行结束该片空间会被系统释放，但该地址任然存在变成了未定义空间
    return &i; // warning:address of stack memory associated with local variable 'i' returned [-Wreturn-stack-address]
}

int main()
{
    int *i = test();

    printf("main i address => %p\n", &i);
    printf("i = %d\n", *i);
    return 0;
}
