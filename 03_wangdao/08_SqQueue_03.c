#include <stdio.h>

#define MAXSIZE 5
/**
 * @brief
 * rear 指向对尾元素的下一个节点
 *
 */
typedef struct
{
    int data[MAXSIZE];
    int front;
    int rear;
    // 标记上一次操作是入栈还是出栈 以区分队满还是队空
    // 0 代表出栈，1代表入栈
    int tag;
} SqQueue;

void initSqQuenue(SqQueue *q);
int enQuenue(SqQueue *q, int elem);
int isFull(SqQueue q);
int deQuenue(SqQueue *q, int *delELem);
int isEmpty(SqQueue q);
int getHead(SqQueue q);
void showSqQuenue(SqQueue q);
int getLenght(SqQueue q);

int getLenght(SqQueue q)
{
    if (q.rear != q.front)
        return (q.rear - q.front + MAXSIZE) % MAXSIZE;
    else
    {
        if (q.tag)
            return MAXSIZE;
        return 0;
    }
}

void showSqQuenue(SqQueue q)
{
    if (isEmpty(q))
    {
        printf("showSqQuenue:q is NULL\n");
        return;
    }
    // 循环迭代次数
    int len = getLenght(q);
    // 队头元素开始迭代
    int seq = q.front;
    // 从对头元素迭代到对尾
    for (int i = 0; i < len; i++)
    {
        printf("%d%s", q.data[seq], i == len - 1 ? "\n" : "->");
        seq = (seq + 1) % MAXSIZE;
    }
}

int getHead(SqQueue q)
{
    return isEmpty(q) ? -1 : q.data[q.front];
}

int isEmpty(SqQueue q)
{
    return q.rear == q.front && !q.tag;
}

int deQuenue(SqQueue *q, int *delELem)
{
    if (isEmpty(*q))
    {
        printf("deQuenue fail,case by : q is empty\n");
        *delELem = -1;
        return 0;
    }
    *delELem = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    q->tag = 0;
    return 1;
}

int isFull(SqQueue q)
{
    return q.rear == q.front && q.tag == 1;
}

int enQuenue(SqQueue *q, int elem)
{
    if (isFull(*q))
    {
        printf("enQuenue fail,case by:q is Full\n");
        return 0;
    }
    q->data[q->rear] = elem;
    q->rear = (q->rear + 1) % MAXSIZE;
    q->tag = 1;
    return 1;
}

void initSqQuenue(SqQueue *q)
{
    q->front = 0;
    q->rear = 0;
    // tag 区分空满情况，顾空和满的先决条件都可以是 q.rear == q.front;
    q->tag = 0;
}

int main()
{

    SqQueue q;
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