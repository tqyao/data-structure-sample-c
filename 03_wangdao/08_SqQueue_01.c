#include <stdio.h>

#define MAXSIZE 5

/**
 * @brief
 * 对尾指针指向对尾元素的下一个节点
 *
 */
typedef struct
{
    int data[MAXSIZE];
    int front;
    int rear;
} SqQuenue;

void initSqQuenue(SqQuenue *q);
int enQuenue(SqQuenue *q, int elem);
int isFull(SqQuenue q);
int deQuenue(SqQuenue *q, int *delELem);
int isEmpty(SqQuenue q);
int getHead(SqQuenue q);
void showSqQuenue(SqQuenue q);
int getLenght(SqQuenue q);

int getLenght(SqQuenue q)
{
    return (q.rear - q.front + MAXSIZE) % MAXSIZE;
}

void showSqQuenue(SqQuenue q)
{
    if (isEmpty(q))
    {
        printf("showSqQuenue:q is NULL\n");
        return;
    }
    int len = getLenght(q); // 循环迭代次数
    int seq = q.front;
    for (int i = 0; i < len; i++)
    {
        printf("%d%s", q.data[seq], i == len - 1 ? "\n" : "->");
        seq = (seq + 1) % MAXSIZE;
    }
}

int getHead(SqQuenue q)
{
    return isEmpty(q) ? -1 : q.data[q.front];
}

int isEmpty(SqQuenue q)
{
    return q.front == q.rear;
}

int deQuenue(SqQuenue *q, int *delELem)
{
    if (isEmpty(*q))
    {
        printf("deQuenue fail,case by : q is empty\n");
        *delELem = -1;
        return 0;
    }
    *delELem = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return 1;
}

int isFull(SqQuenue q)
{
    // return q.front == q.rear;
    return (q.rear + 1) % MAXSIZE == q.front;
}

int enQuenue(SqQuenue *q, int elem)
{
    if (isFull(*q))
    {
        printf("enQuenue fail,case by:q is Full\n");
        return 0;
    }
    q->data[q->rear] = elem;
    q->rear = (q->rear + 1) % MAXSIZE;
    return 1;
}

void initSqQuenue(SqQuenue *q)
{
    q->front = 0;
    q->rear = 0;
}
int main()
{

    SqQuenue q;
    initSqQuenue(&q);
    showSqQuenue(q);

    enQuenue(&q, 777);
    showSqQuenue(q);

    int delELem = -1;
    printf("%s,delElem = %d\n", deQuenue(&q, &delELem) ? "删除成功" : "删除失败", delELem);
    showSqQuenue(q);
    printf("getHead(q)=>%d\n", getHead(q));

    delELem = -1;
    printf("%s,delElem = %d\n", deQuenue(&q, &delELem) ? "删除成功" : "删除失败", delELem);
    showSqQuenue(q);

    enQuenue(&q, 888);
    showSqQuenue(q);

    enQuenue(&q, 999);
    showSqQuenue(q);

    enQuenue(&q, 111);
    showSqQuenue(q);

    printf("getHead(q)=>%d\n", getHead(q));

    enQuenue(&q, 222);
    showSqQuenue(q);

    enQuenue(&q, 444);
    showSqQuenue(q);

    delELem = -1;
    printf("%s,delElem = %d\n", deQuenue(&q, &delELem) ? "删除成功" : "删除失败", delELem);
    showSqQuenue(q);

    delELem = -1;
    printf("%s,delElem = %d\n", deQuenue(&q, &delELem) ? "删除成功" : "删除失败", delELem);
    showSqQuenue(q);

    enQuenue(&q, 456);
    showSqQuenue(q);

    return 0;
}