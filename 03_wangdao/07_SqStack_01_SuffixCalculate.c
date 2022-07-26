#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 10

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

void initStack(SqStack *S);
int isEmpty(SqStack S);
int isFull(SqStack S);
int push(SqStack *S, int elem);
void showStack(SqStack S);
int pop(SqStack *S, int *delElem);
int getTop(SqStack S);
int InfixToSuffix01(char infix[], int len, char suffix[]);
int getPriority01(char ch);
// int compareOP(char ch1, char ch2);

void InfixToSuffix(char *infix, char *suffix);
int getPriority(char operator);
int compareOperator(char ch1, char ch2);

int suffixCalculate(char *suffix, int *res);
void calBetweenNum(char oprator, SqStack *stack);

/**
 * @brief
 * 指定符号计算操作数
 *
 * @param oprator
 * @param stack
 */
void calBetweenNum(char oprator, SqStack *stack)
{
    int num1 = -1, num2 = -1;
    pop(stack, &num1);
    pop(stack, &num2);
    if (num1 == -1 || num2 == -1)
    {
        printf("calBetweenNum fail,case by : num1 == -1 || num2 == -1\n");
        exit(1);
    }
    if (oprator == '+')
        num1 = num2 + num1;
    else if (oprator == '-')
        num1 = num2 - num1;
    else if (oprator == '*')
        num1 = num2 * num1;
    else if (oprator == '/')
        num1 = num2 / num1;
    push(stack, num1);
}

/**
 * @brief
 * 后缀表达式的计算
 *
 * @param suffix
 * @param res
 * @return int
 */
int suffixCalculate(char *suffix, int *res)
{

    SqStack stack;
    initStack(&stack);
    char *p = suffix;
    int num = 0;

    while (*p)
    {
        // 1. 空格直接跳过
        if (*p == ' ')
        {
            p++;
            continue;
        }
        // 2. 如果是数字直接入栈
        else if (*p > '0' && *p < '9')
        {
            // 多个位数相加
            while (1)
            {
                num += *(p++) - '0';
                if (*p < '0' || *p > '9')
                    break;
                num *= 10;
            }
            if (!push(&stack, num))
            {
                printf("suffixCalculate fail,case by:!push(&stack, num) is 0;\n");
                return 0;
            }
            num = 0;
        }
        // 3. 如果是运算符则弹出栈顶两个元素，先弹出的作为右操作数
        else if (*p == '+' || *p == '-' || *p == '*' || *p == '/')
        {
            calBetweenNum(*p, &stack);
            p++;
        }
        else
        {
            printf("suffixCalculate fail,case by : oprator is illeagl\n");
            return 0;
        }
    }

    pop(&stack, res);
    return 1;
}

int getPriority(char operator)
{
    if (operator== '+' || operator== '-')
        return 1;
    else if (operator== '*' || operator== '/')
        return 2;
    printf("getPriority fail,case by: operator is illeagl\n");
    exit(1);
}

/**
 * @brief
 * 比较两个运算符优先级
 *
 * @param ch1
 * @param ch2
 * @return int
 * 1: ch1 大于 ch2
 * 0: ch1 等于 ch2
 * -1: ch1 小于 ch2
 */
int compareOperator(char ch1, char ch2)
{
    return getPriority(ch1) - getPriority(ch2);
}

/**
 * @brief
 * 中缀转后缀
 * @param infix
 * @param suffix
 */
void InfixToSuffix(char *infix, char *suffix)
{

    SqStack stack;
    initStack(&stack);

    // 循环迭代次数
    int len = strlen(infix);
    int sufIdx = 0;
    char currentCh = 0;
    int popELem = -1;

    for (int i = 0; i < len; i++)
    {
        currentCh = infix[i];
        // 1. 空格直接略过
        if (currentCh == ' ')
            continue;
        // 2. 数字直接加入后缀表达式
        else if (currentCh >= '0' && currentCh <= '9')
            suffix[sufIdx++] = currentCh;
        // 3. 遇到 + - 符号，若栈不为空且栈顶元素不为'('则依次弹出栈顶元素加入到后缀表达式直到 '(' 后入栈（因为+ - 运算符优先级最低，无论如何都可以后运算）
        // ，若栈为空则直接入栈
        else if (currentCh == '+' || currentCh == '-')
        {
            // 隔开两位以上数字
            suffix[sufIdx++] = ' ';
            while (!isEmpty(stack) && getTop(stack) != '(')
            {
                pop(&stack, &popELem);
                suffix[sufIdx++] = popELem;
            }
            if (!push(&stack, currentCh))
                return;
        }
        // 4. 遇到 * / 符号，若符号栈不为空且栈顶元素不为 '(' 且栈顶元素优先大于等于当前符号优先级，则依次弹出栈中符号
        // 加入后缀表达式后再入栈（因为此时只有一个数字+一个操作符，无法计算必须先入栈）
        else if (currentCh == '*' || currentCh == '/')
        {
            // 隔开两位以上数字
            suffix[sufIdx++] = ' ';
            while (!isEmpty(stack) && getTop(stack) != '(' && compareOperator(getTop(stack), currentCh) >= 0)
            {
                pop(&stack, &popELem);
                suffix[sufIdx++] = popELem;
            }

            // 有可能栈满，需要判断一下
            if (!push(&stack, currentCh))
                return;
        }
        // 5. 遇到 '(' 直接入栈
        else if (currentCh == '(')
        {
            // 有可能栈满，需要判断一下
            if (!push(&stack, currentCh))
                return;
        }
        // 6. 遇到 ')' ，依次弹出符号栈中的符加入到后缀表达式号直到 '(' 结束，并吧'('出栈
        else if (currentCh == ')')
        {
            while (!isEmpty(stack) && getTop(stack) != '(')
            {
                pop(&stack, &popELem);
                suffix[sufIdx++] = popELem;
            }
            pop(&stack, &popELem);
        }
        else
        {
            printf("InfixToSuffix fail,case by currentCh is illeagl\n");
            return;
        }
    }
    // 7. 弹出栈中剩余符号
    while (!isEmpty(stack))
    {
        pop(&stack, &popELem);
        suffix[sufIdx++] = popELem;
    }
    suffix[sufIdx] = '\0';
}

/**
 * @brief Get the Priority object
 * 获取运算符优先级
 *
 * @param ch
 * @return int
 */
int getPriority01(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    printf("getPriority fail,case by : ch is illegal\n");
    exit(0);
    return -3;
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
        *delElem = -1;
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
    /**************************/
    // char expression[] = "2*(10/(3+1))";
    char expression[] = "((15/(7-(1+1)))*3)-(2+(1+1))";
    // char expression[] = "2*3";
    char suffix[100] = {0};
    InfixToSuffix(expression, suffix);
    char *p = suffix;
    while (*p)
        printf("%c", *(p++));
    printf("\n");
    /**************************/

    // char *suffix01 = "1 1+2 3*+";
    int result = 0;
    // printf("suffixCalculate function return value => %d\nresult = %d\n", suffixCalculate(suffix01, &result), result);
    printf("suffixCalculate function return value => %d\nresult = %d\n", suffixCalculate(suffix, &result), result);

    return 1;
}