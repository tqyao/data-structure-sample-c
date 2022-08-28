#include <stdio.h>
#include <stdlib.h>
/**
 * @brief
 * 不带头节点的单链表栈实现：
 * 实质上就是限制在链表的一端插入或删除
 */
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} * LiStack;

int isEmpty(LiStack S);
void showLiStack(LiStack S);
int push(LiStack *S, int elem);
int pop(LiStack *S, int *delElem);
LiStack createEmptyNode();
int getTop(LiStack S);

int getTop(LiStack S)
{
    if (isEmpty(S))
        return 0;
    return S->data;
}

int pop(LiStack *S, int *delElem)
{
    if (isEmpty(*S))
    {
        printf("pop fail,case by:S is NULL\n");
        *delElem = -1;
        return 0;
    }

    // 要删除节点的下一个节点
    LiStack p = (*S)->next;
    // p为空 下一个节点为空，说明链表栈只有1个节点，直接删除首节点
    if (isEmpty(p))
    {
        *delElem = (*S)->data;
        // free：指针所指向的堆内存空间被释放，但指针(*S)所指向的内存地址任然没变，此时指针指向的是未定义的’垃圾内容‘，变成了野指针。
        /* 野指针：指向内存被释放的内存或者没有访问权限的内存的指针。 */
        free(*S);
        *S = NULL;
        return 1;
    }

    // S 的 length >= 2 的情况
    (*S)->next = p->next;
    *delElem = (*S)->data;
    (*S)->data = p->data;
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

int push(LiStack *S, int elem)
{
    LiStack p = createEmptyNode();
    if (p == NULL)
        return 0;
    p->data = elem;
    p->next = (*S);
    *S = p;
    return 1;
}

void showLiStack(LiStack S)
{
    if (isEmpty(S))
    {
        printf("showLiStack : S is NULL\n");
        return;
    }
    LiStack p = S;
    while (!isEmpty(p))
    {
        printf("%d%s", p->data, isEmpty(p->next) ? "\n" : "->");
        p = p->next;
    }
}

int isEmpty(LiStack S)
{
    return S == NULL;
}

int main()
{
    // LiStack S;   // 声明不赋初始值是个不好的习惯>,< 会有内存脏数据
    LiStack S = NULL;
    showLiStack(S);

    push(&S, 777);
    showLiStack(S);

    push(&S, 888);
    showLiStack(S);

    printf("getTop(S) = %d\n", getTop(S));

    push(&S, 999);
    showLiStack(S);

    int delElem = -1;
    printf("%s,delElem = %d\n", pop(&S, &delElem) ? "删除成功" : "删除失败", delElem);
    showLiStack(S);

    delElem = -1;
    printf("%s,delElem = %d\n", pop(&S, &delElem) ? "删除成功" : "删除失败", delElem);
    showLiStack(S);

    push(&S, 5566);
    showLiStack(S);

    delElem = -1;
    printf("%s,delElem = %d\n", pop(&S, &delElem) ? "删除成功" : "删除失败", delElem);
    showLiStack(S);

    delElem = -1;
    printf("%s,delElem = %d\n", pop(&S, &delElem) ? "删除成功" : "删除失败", delElem);
    showLiStack(S);

    printf("getTop(S) = %d\n", getTop(S));
    return 0;
}