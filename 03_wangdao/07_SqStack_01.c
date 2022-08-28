#include <stdio.h>

#define MAXSIZE 5

/**
 * @brief
 * 栈顶指针指向栈中的最后一个元素节点
 * @descript
 * malloc声明的内存空间会返回在堆中开辟的内存地址，而顺序存储栈是直接声明在栈中的，
 * 系统会自动回收，固不需要手动销毁
 */
typedef struct
{
    int data[MAXSIZE];
    int top;
} SqStack;

// 参数如果不加 * 则只是拷贝一份实参副本（深拷贝，引用对象属性会被逐一赋值到新地址内存空间存储），对副本操作并不会影响到实参
// void initStack(SqStack S);
// void initStack(SqStack S)
// {
//     // printf("%d\n", S.top);
//     S.top = -1;
// }

void initStack(SqStack *S);
int isEmpty(SqStack S);
int isFull(SqStack S);
int push(SqStack *S, int elem);
void showStack(SqStack S);
int pop(SqStack *S, int *delElem);
int getTop(SqStack S);

int getTop(SqStack S)
{
    return isEmpty(S) ? 0 : S.data[S.top];
}
int pop(SqStack *S, int *delElem)
{
    if (isEmpty(*S))
    {
        printf("pop fail,case by : S is empty\n");
        return 0;
    }
    *delElem = S->data[S->top--];
    return 1;
}

void showStack(SqStack S)
{
    if (isEmpty(S))
    {
        printf("showStack: S is NULL\n");
        return;
    }

    int len = S.top;
    for (int i = len; i >= 0; i--)
    {
        printf("%d%s", S.data[i], !i ? "\n" : "->");
    }
}

int push(SqStack *S, int elem)
{
    if (isFull(*S))
    {
        printf("push fail,case by: S is FUll\n");
        return 0;
    }
    S->data[++S->top] = elem;
    return 1;
}

int isFull(SqStack S)
{
    return S.top + 1 == MAXSIZE;
}
int isEmpty(SqStack S)
{
    return S.top == -1;
}
void initStack(SqStack *S)
{
    S->top = -1; // 栈顶指针指向栈最后一个元素节点索引
}

int main()
{
    // SqStack S;
    // printf("%d\n", S.top);
    // initStack(S);
    // printf("%d\n", S.top);

    SqStack S;
    initStack(&S);

    showStack(S);
    push(&S, 777);
    showStack(S);

    push(&S, 666);
    showStack(S);

    push(&S, 333);
    showStack(S);

    push(&S, 369);
    showStack(S);

    push(&S, 123);
    showStack(S);

    push(&S, 999);
    showStack(S);

    int delElem = -1;
    printf("%s,delElem=%d\n", pop(&S, &delElem) ? "出栈成功" : "出栈失败", delElem);
    showStack(S);

    // delElem = -1;
    // printf("%s,delElem=%d\n", pop(&S, &delElem) ? "出栈成功" : "出栈失败", delElem);
    // showStack(S);

    // delElem = -1;
    // printf("%s,delElem=%d\n", pop(&S, &delElem) ? "出栈成功" : "出栈失败", delElem);
    // showStack(S);

    // delElem = -1;
    // printf("%s,delElem=%d\n", pop(&S, &delElem) ? "出栈成功" : "出栈失败", delElem);
    // showStack(S);

    // delElem = -1;
    // printf("%s,delElem=%d\n", pop(&S, &delElem) ? "出栈成功" : "出栈失败", delElem);
    // showStack(S);

    // delElem = -1;
    // printf("%s,delElem=%d\n", pop(&S, &delElem) ? "出栈成功" : "出栈失败", delElem);
    // showStack(S);

    printf("getTop(S) = %d\n", getTop(S));
    return 0;
}