#include <stdio.h>
#include <stdlib.h>
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LiStack;

void test(LiStack S)
{
    printf("test => %p\n", &S);
    printf("test01 s.data = %d\n", S.data);
    printf("test s.data pointer =>%p\n", &S.data);
    printf("test s.next pointer =>%p\n", &S.next);
    S.data = 1; //改变形参，不会影响到实参
    printf("test02 s.data = %d\n", S.data);
}

int main01()
{
    // 求证：非指针类型传递的参数，实参会被拷贝一份副本（深拷贝）到函数形参内部使用，这是形参与实参在堆中各自有各自的内存空间存储数据
    LiStack S;
    S.data = 2;
    printf("main01 => %p\n", &S);
    printf("main01 s.data = %d\n", S.data);
    printf("main s.data pointer =>%p\n", &S.data);
    printf("main s.next pointer =>%p\n", &S.next);
    test(S);
    printf("main01 after => %p\n", &S);
    printf("main01 after s.data = %d\n", S.data);
    return 1;
}

#define MAXSIZE 5
typedef struct
{
    int data[MAXSIZE];
    int top;

} ShareStack, *SStack;

void test02(ShareStack S)
{
    printf("test02 S.data[0] = %d\n", S.data[0]);
    printf("test02 S.data pointer => %p\n", &S.data);
    S.data[0] = 456;
    printf("test02 02 S.data[0] = %d\n", S.data[0]);
}

void test03(SStack SS)
{
    printf("test03 S->data[0] = %d \n", SS->data[0]);
}

int main()
{
    /****************************************/
    /* 直接传递实例 */
    // ShareStack S;
    // S.data[0] = 123;
    // printf("main S.data[0] = %d\n", S.data[0]);
    // printf("main S.data pointer => %p\n", &S.data);
    // test02(S);
    // printf("main02 02 S.data[0] = %d\n", S.data[0]);
    /****************************************/

    /****************************************/

    /* 直接声明一个SStack SS1; 相当于 ShareStack *SS1;
     * 声明指针不赋予初始值，指针指向未知内存空间，相当于野指针，c语言不允许对野指针赋值，如果野指针指向系统受保护内存（不可读写），
     * 则也不允许访问
     */
    SStack SS1;
    // SS1->top = 111; // error
    printf("%d\n", SS1->top); // 有概率报错，取决于该随机内存是否受保护

    /* 传递引用*/
    SStack SS = (SStack)malloc(sizeof(ShareStack));
    SS->data[0] = 123;
    // SS->top = 111;
    printf("main S->data[0] = %d \n", SS->data[0]);
    /****************************************/
}
