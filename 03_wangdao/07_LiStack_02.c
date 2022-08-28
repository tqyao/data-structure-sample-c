#include <stdio.h>
#include <stdlib.h>
/**
 * @brief
 * 带头节点的单链表栈实现：
 * 实质上就是限制在链表的一端插入或删除
 *
 * typedef 重命名链表栈为指针：这样在函数参数传递时就无需多加 * 声明参数为指针了。此外由于是链表结构实现栈（其实顺序表也类似），无论是
 * 入栈还是出栈，新增删除节点都希望对原链表产生影响，所以传递引用比较合适方便
 */
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} * LiStack; // 重名成指针

int isEmpty(LiStack S);
void showLiStack(LiStack S);
// 注意这里的pop push 不需要再传递引用（不需要传递一级指针的地址），因为带头结点的栈，入栈和出栈的无论何种情况都不需要对形参赋值操作。
/* 不带头节点的栈需要传递引用，例如入栈：当第一次入栈，需要通过给形参赋值初始化一个节点，并且此次赋值也要影响到调用时的实参。
 *  再例如出栈：当最后一个节点出栈时，除了要释放掉该节点malloc的内存外，还需要通过形参（二级指针） 赋值NULL，并且此赋值操作需要影响调用时的实参，所以必须传递引用。
 */
int push(LiStack S, int elem);
int pop(LiStack S, int *delElem);
LiStack createEmptyNode();
int getTop(LiStack S);
LiStack initLiStack();

LiStack initLiStack()
{
    // 初始化头节点
    LiStack p = createEmptyNode();
    if (p == NULL)
    {
        printf("exec initLiStack \n");
        exit(1);
    }
    return p;
}

int getTop(LiStack S)
{
    if (isEmpty(S))
        return 0;
    return S->next->data;
}

int pop(LiStack S, int *delElem)
{
    if (isEmpty(S))
    {
        printf("pop fail,case by:S is NULL\n");
        *delElem = -1;
        return 0;
    }
    // 要删除的节点
    LiStack p = S->next;
    *delElem = p->data;
    S->next = p->next;
    free(p);
    return 1;
}

LiStack createEmptyNode()
{
    LiStack p = (LiStack)malloc(sizeof(struct LinkNode));
    if (p == NULL)
    {
        printf("createEmptyNode fail,case by : out of memery\n");
        return NULL;
    }
    p->data = 0;
    p->next = NULL;
    return p;
}

int push(LiStack S, int elem)
{
    printf("push &S => %p\n", &S);                         // 不同
    printf("push S value => %p\n", S);                     // 相同
    printf("push S->next value => %p\n", S->next);         // 相同
    printf("push S->next 's address => %p\n", &(S->next)); // 相同，S->next 取到的是原始实例，自然 & 所取到的也是与原始实例相同

    LiStack p = createEmptyNode();
    if (p == NULL)
        return 0;
    p->data = elem;
    p->next = S->next;
    S->next = p;
    return 1;
}

void showLiStack(LiStack S)
{
    if (isEmpty(S))
    {
        printf("showLiStack : S is NULL\n");
        return;
    }
    LiStack p = S->next;
    while (p != NULL)
    {
        printf("%d%s", p->data, p->next ? "->" : "\n");
        p = p->next;
    }
}
/**
 * @brief
 * 判断带头节点的栈是否为空
 *
 * @param S
 * @return int
 */
int isEmpty(LiStack S)
{
    return S->next == NULL;
}

int main()
{
    LiStack S = initLiStack();
    showLiStack(S);
    printf("main &S => %p\n", &S);
    printf("main S value => %p\n", S);
    printf("main S->next value => %p\n", S->next);
    printf("main S->next 's address => %p\n", &(S->next));

    push(S, 777);
    showLiStack(S);

    push(S, 888);
    showLiStack(S);

    printf("getTop(S) = %d\n", getTop(S));

    push(S, 999);
    showLiStack(S);

    int delElem = -1;
    printf("%s,delElem = %d\n", pop(S, &delElem) ? "删除成功" : "删除失败", delElem);
    showLiStack(S);

    delElem = -1;
    printf("%s,delElem = %d\n", pop(S, &delElem) ? "删除成功" : "删除失败", delElem);
    showLiStack(S);

    push(S, 5566);
    showLiStack(S);

    delElem = -1;
    printf("%s,delElem = %d\n", pop(S, &delElem) ? "删除成功" : "删除失败", delElem);
    showLiStack(S);

    delElem = -1;
    printf("%s,delElem = %d\n", pop(S, &delElem) ? "删除成功" : "删除失败", delElem);
    showLiStack(S);

    delElem = -1;
    printf("%s,delElem = %d\n", pop(S, &delElem) ? "删除成功" : "删除失败", delElem);
    showLiStack(S);

    printf("getTop(S) = %d\n", getTop(S));
    return 1;
}