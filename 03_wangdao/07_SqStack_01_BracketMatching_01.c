#include <stdio.h>
#include <string.h>
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

int BrackKetMatching(char arrs[], int size);
// todo:尝试不用栈实现括号匹配（就是再实现一遍栈的基本操作）
int BrackKetMatching02(char arrs[], int len);
/**
 * @brief
 *
 * 栈实际应用：括号匹配
 *
 * @param arrs：需要匹配的字符数组
 * @return int：0->不匹配；1->匹配
 */
int BrackKetMatching(char arrs[], int len)
{
    SqStack S;
    initStack(&S);

    for (int i = 0; i < len; i++)
    {
        char ch = arrs[i];
        // 判断括号类型
        if ('(' == ch || '[' == ch || '{' == ch)
            // 左括号直接入栈
            push(&S, ch);
        else if (')' == ch || ']' == ch || '}' == ch)
        {
            int popInt = -1;
            pop(&S, &popInt);
            if (popInt == -1)
                // 栈空，当前字符剩余（当前字符不匹配），返回0
                return 0;
            //出栈检查左括号与当前右括号配对
            if (!(popInt == '(' && ch == ')' || popInt == '[' && ch == ']' || popInt == '{' && ch == '}'))
                // 左右括号不配对，返回0
                return 0;
            //否者就是配对成功，读取进入下一个循环判断
        }
        else
            // 非法括号类型直接结束
            // printf("BrackKetMatching fail,case by ch is illegal\n");
            return 0;
    }
    // 是否有剩余未配对左括号
    return isEmpty(S);
}

int BrackKetMatching02(char arrs[], int len)
{
    return 0;
}

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
    // char arry[] = {'(', '[', '{', '}', ']', ')'};
    char arry[10] = {'(', '[', '{', '}', '\0'};

    int len = strlen(arry);
    for (int i = 0; i < len; i++)
        printf("%c%s", arry[i], i == len / 2 - 1 ? "\n" : " ");
    printf("=> %s\n", BrackKetMatching(arry, len) ? "匹配成功" : "匹配失败");

    printf("\n");
    char str2[] = "([{}])";
    memcpy(arry, str2, sizeof(str2));
    len = strlen(arry);
    for (int i = 0; i < len; i++)
        printf("%c%s", arry[i], i == len / 2 - 1 ? "\n" : " ");
    printf("=> %s\n", BrackKetMatching(arry, strlen(arry)) ? "匹配成功" : "匹配失败");

    printf("\n");
    char str3[] = "(([{}])";
    memcpy(arry, str3, sizeof(str3));
    len = strlen(arry);
    for (int i = 0; i < len; i++)
        printf("%c%s", arry[i], i == len / 2 - 1 ? "\n" : " ");
    printf("=> %s\n", BrackKetMatching(arry, strlen(arry)) ? "匹配成功" : "匹配失败");

    printf("\n");
    char str4[] = "]()";
    memcpy(arry, str4, sizeof(str4));
    len = strlen(arry);
    for (int i = 0; i < len; i++)
        printf("%c%s", arry[i], i == len / 2 - 1 ? "\n" : " ");
    printf("=> %s\n", BrackKetMatching(arry, strlen(arry)) ? "匹配成功" : "匹配失败");

    return 0;
}