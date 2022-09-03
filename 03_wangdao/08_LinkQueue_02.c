#include <stdio.h>
#include <stdlib.h>

/**
 * @brief
 * 不带头节点的队列实现
 *
 */

// 单链表节点，即队列节点
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;

void initLinkQueue(LinkQueue *Q);
int enQueue(LinkQueue *Q, int elem);
LinkNode *createLinkNode(int elem);
void showLinkQueue(LinkQueue Q);
int isEmpty(LinkQueue Q);
int deQueue(LinkQueue *Q, int *delElem);
int getHead(LinkQueue Q);

int getHead(LinkQueue Q)
{
    return Q.front ? Q.front->data : 0;
}

int deQueue(LinkQueue *Q, int *delElem)
{
    if (isEmpty(*Q))
    {
        printf("deQueue fail, case by : Q is NULL\n");
        *delElem = -1;
        return 0;
    }
    LinkNode *p = Q->front;
    *delElem = p->data;
    if (p == Q->rear)
        Q->rear = Q->front = NULL;
    Q->front = p->next;
    free(p);
    return 1;
}

int isEmpty(LinkQueue Q)
{
    // return Q.rear == NULL;
    return Q.front == NULL;
}

void showLinkQueue(LinkQueue Q)
{
    if (isEmpty(Q))
    {
        printf("showLinkQueue: Q is NULL\n");
        return;
    }
    LinkNode *p = Q.front;
    while (p != NULL)
    {
        printf("%d%s", p->data, p->next ? "->" : "\n");
        p = p->next;
    }
}

LinkNode *createLinkNode(int elem)
{
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    if (p == NULL)
    {
        printf("createLinkNode fail,case by : out of memery\n");
        return NULL;
    }
    p->data = elem;
    p->next = NULL;
    return p;
}

int enQueue(LinkQueue *Q, int elem)
{
    LinkNode *p = createLinkNode(elem);
    if (p == NULL)
    {
        printf("enQueue fail,case by : p is NULL\n");
        return 0;
    }
    // 如果出入的节点作为链表第一个节点，则头尾指针指向该节点
    if (isEmpty(*Q))
    {
        Q->front = Q->rear = p;
        return 1;
    }
    Q->rear->next = p;
    Q->rear = p;
    return 1;
}

void initLinkQueue(LinkQueue *Q)
{
    Q->front = Q->rear = NULL;
}

int main()
{
    LinkQueue Q;
    initLinkQueue(&Q);
    showLinkQueue(Q);

    int delELem = -1;
    printf("%s,delElem = %d\n", deQueue(&Q, &delELem) ? "删除成功" : "删除失败", delELem);
    showLinkQueue(Q);
    printf("getHead(q)=>%d\n", getHead(Q));

    enQueue(&Q, 777);
    showLinkQueue(Q);

    delELem = -1;
    printf("%s,delElem = %d\n", deQueue(&Q, &delELem) ? "删除成功" : "删除失败", delELem);
    showLinkQueue(Q);
    printf("getHead(q)=>%d\n", getHead(Q));

    delELem = -1;
    printf("%s,delElem = %d\n", deQueue(&Q, &delELem) ? "删除成功" : "删除失败", delELem);
    showLinkQueue(Q);
    printf("getHead(q)=>%d\n", getHead(Q));

    enQueue(&Q, 888);
    showLinkQueue(Q);

    enQueue(&Q, 999);
    showLinkQueue(Q);
    printf("getHead(q)=>%d\n", getHead(Q));

    enQueue(&Q, 123);
    showLinkQueue(Q);

    return 0;
}