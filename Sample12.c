#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    // ElementType Element;
    // Position    Next;
    int elem; //初始化不涉及节点内容,随便写一个
    struct Node *next;
} Node;

typedef Node *PtrToNode;
typedef PtrToNode List;

void InitList(List *L)
{
    (*L) = (Node *)malloc(sizeof(Node)); // 方式一传递会报错
    if ((*L) == NULL)
    {
        printf("\n Failed to malloc memory to init List!\n");
        exit(1);
    }
    (*L)->elem = 0;
    (*L)->next = NULL;
    printf("malloc done.\n");
}

int main()
{

    // 方式一：
    List *L02;     // Node **L02    申明二级指针并未赋予初始值
    InitList(L02); // 这样传递会报错，传递的实质上是
    // (*L02) = (Node *)malloc(sizeof(Node)); // 方式一传递会报错：野指针不允许赋值
    printf("%d\n", (*L02)->elem); // 野指针可以访问
    // 报错原因：指针L02 声明未赋值，是野指针（随机地址），c语言不允许给野指针赋值

    // 方式二：
    // List L;  // Node *L
    // InitList(&L); //这里改了
    // printf("L->elem=%d\n", L->elem);
}