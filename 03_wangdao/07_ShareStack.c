#include <stdio.h>

#define MAXSIZE 10

typedef struct
{
    int data[MAXSIZE];
    int top01;
    int top02;
} ShareStack;

void initShareStack(ShareStack *S);
int isEmpty(ShareStack S, int seq);
int isFull(ShareStack S);
void showShareStack(ShareStack S);
int push(ShareStack *S, int elem, int seq);
int pop(ShareStack *S, int *delElem, int seq);

int pop(ShareStack *S, int *delElem, int seq)
{
    *delElem = -1;
    int res = 0;
    switch (seq)
    {
    case 1:
        if (isEmpty(*S, 1))
            printf("pop fail,case by : Stack 01 is empty\n");
        else
        {
            *delElem = S->data[S->top01--];
            res = 1;
        }
        break;
    case 2:
        if (isEmpty(*S, 2))
            printf("pop fail,case by : Stack 02 is empty\n");
        else
        {
            *delElem = S->data[S->top02--];
            res = 1;
        }
        break;
    default:
        printf("pop fail,case by : seq is illegel\n");
        break;
    }
    return res;
}

int push(ShareStack *S, int elem, int seq)
{
    int res = 0;
    if (seq == 1)
    {
        if (isFull(*S))
            printf("push fail, case by : stack 01 is FULL\n");
        else
        {
            S->data[++S->top01] = elem;
            res = 1;
        }
    }
    else if (seq == 2)
    {
        if (isFull(*S))
            printf("push fail, case by : stack 02 is FULL\n");
        else
        {
            S->data[--S->top02] = elem;
            res = 1;
        }
    }
    // (seq != 1 || seq != 2)
    else
        printf("push fail,case by : seq is illegel\n");

    return res;
}

void showShareStack(ShareStack S)
{
    int len;
    if (isEmpty(S, 1))
        printf("showShareStack: Stack 01 is NULL\n");
    else
    {
        len = S.top01;
        printf("stack 01 => ");
        for (int i = len; i >= 0; i--)
            printf("%d%s", S.data[i], i ? "->" : "\n");
    }

    if (isEmpty(S, 2))
    {
        printf("showShareStack: Stack 02 is NULL\n");
        return;
    }

    len = S.top02;
    printf("stack 02 => ");
    for (int i = len; i < MAXSIZE; i++)
        printf("%d%s", S.data[i], i == MAXSIZE - 1 ? "\n" : "->");
}

int isFull(ShareStack S)
{
    return S.top01 + 1 == S.top02;
}
void initShareStack(ShareStack *S)
{
    S->top01 = -1;
    S->top02 = MAXSIZE;
}

int isEmpty(ShareStack S, int seq)
{
    return seq == 1 ? S.top01 == -1 : S.top02 == MAXSIZE;
}

int main()
{
    ShareStack S;
    initShareStack(&S);
    showShareStack(S);

    push(&S, 777, 1);
    push(&S, 777, 2);
    showShareStack(S);

    push(&S, 888, 1);
    push(&S, 888, 2);
    showShareStack(S);

    push(&S, 999, 1);
    push(&S, 999, 2);
    showShareStack(S);

    push(&S, 123, 1);
    push(&S, 123, 2);
    showShareStack(S);

    push(&S, 456, 1);
    push(&S, 456, 2);
    showShareStack(S);

    push(&S, 2233, 1);
    push(&S, 2233, 2);
    showShareStack(S);

    int delELem = -1;
    printf("%s,delElem = %d\n", pop(&S, &delELem, 1) ? "删除成功" : "删除失败", delELem);
    showShareStack(S);

    delELem = -1;
    printf("%s,delElem = %d\n", pop(&S, &delELem, 1) ? "删除成功" : "删除失败", delELem);
    showShareStack(S);

    delELem = -1;
    printf("%s,delElem = %d\n", pop(&S, &delELem, 1) ? "删除成功" : "删除失败", delELem);
    showShareStack(S);

    delELem = -1;
    printf("%s,delElem = %d\n", pop(&S, &delELem, 1) ? "删除成功" : "删除失败", delELem);
    showShareStack(S);

    delELem = -1;
    printf("%s,delElem = %d\n", pop(&S, &delELem, 1) ? "删除成功" : "删除失败", delELem);
    showShareStack(S);

    delELem = -1;
    printf("%s,delElem = %d\n", pop(&S, &delELem, 1) ? "删除成功" : "删除失败", delELem);
    showShareStack(S);

    push(&S, 777, 1);
    showShareStack(S);

    return 0;
}