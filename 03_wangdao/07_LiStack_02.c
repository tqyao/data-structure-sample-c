#include <stdio.h>
#include <stdlib.h>
/**
 * @brief
 * 带头节点的单链表栈实现：
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
LiStack initLiStack();

LiStack initLiStack()
{
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

int pop(LiStack *S, int *delElem)
{
    if (isEmpty(*S))
    {
        printf("pop fail,case by:S is NULL\n");
        *delElem = -1;
        return 0;
    }
    // 要删除的节点
    LiStack p = (*S)->next;
    *delElem = p->data;
    (*S)->next = p->next;
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
    p->next = (*S)->next;
    (*S)->next = p;
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

int isEmpty(LiStack S)
{
    return S->next == NULL;
}

int main()
{
    // // LiStack S;   // 声明不赋初始值是个不好的习惯>,< 会有内存脏数据
    // LiStack S = NULL;
    // showLiStack(S);

    // push(&S, 777);
    // showLiStack(S);

    // push(&S, 888);
    // showLiStack(S);

    // printf("getTop(S) = %d\n", getTop(S));

    // push(&S, 999);
    // showLiStack(S);

    // int delElem = -1;
    // printf("%s,delElem = %d\n", pop(&S, &delElem) ? "删除成功" : "删除失败", delElem);
    // showLiStack(S);

    // delElem = -1;
    // printf("%s,delElem = %d\n", pop(&S, &delElem) ? "删除成功" : "删除失败", delElem);
    // showLiStack(S);

    // push(&S, 5566);
    // showLiStack(S);

    // delElem = -1;
    // printf("%s,delElem = %d\n", pop(&S, &delElem) ? "删除成功" : "删除失败", delElem);
    // showLiStack(S);

    // delElem = -1;
    // printf("%s,delElem = %d\n", pop(&S, &delElem) ? "删除成功" : "删除失败", delElem);
    // showLiStack(S);

    // printf("getTop(S) = %d\n", getTop(S));

    LiStack S = initLiStack();
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
    return 1;
}