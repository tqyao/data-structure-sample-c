#include <stdio.h>

#define MAXSIZE 5

/**
 * @brief
 * 对rear指向对尾元素节点
 *
 */
typedef struct
{
    int data[MAXSIZE];
    int front;
    int rear;
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
    // return (q.rear - q.front + MAXSIZE) % MAXSIZE;
    // （rear - front）会少算一个节点，也就是不包括front节点，所以要加上1
    return (q.rear - q.front + MAXSIZE) % MAXSIZE + 1;
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
    // return q.front == q.rear;
    return (q.rear + 1) % MAXSIZE == q.front;
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
    return 1;
}

int isFull(SqQueue q)
{
    //牺牲一个节点区分队满与队空
    return (q.rear + 2) % MAXSIZE == q.front;
}

int enQuenue(SqQueue *q, int elem)
{
    if (isFull(*q))
    {
        printf("enQuenue fail,case by:q is Full\n");
        return 0;
    }
    // 由于rear指向对尾元素，所以入队时需要先把指针指向下一个空节点在存储数据
    q->rear = (q->rear + 1) % MAXSIZE;
    q->data[q->rear] = elem;
    return 1;
}

void initSqQuenue(SqQueue *q)
{
    q->front = 0;
    // 初始对尾指针指向尾节点，此时代表队列为空
    q->rear = MAXSIZE - 1;
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