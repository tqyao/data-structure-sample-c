#include <stdio.h>
#include <stdlib.h>

/**
 * @brief
 * 带头节点的队列实现
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
    return Q.front->next ? Q.front->next->data : 0;
}

int deQueue(LinkQueue *Q, int *delElem)
{
    if (isEmpty(*Q))
    {
        printf("deQueue fail, case by : Q is NULL\n");
        *delElem = -1;
        return 0;
    }
    LinkNode *p = Q->front->next;
    *delElem = p->data;
    // 说明删除的是最后一个节点，即头指针指向的下一个节点的next指针域为空
    if (p == Q->rear)
        // 让尾指针指向头节点，代表链表为空： Q.front == Q.rear;
        Q->rear = Q->front;
    Q->front->next = p->next;
    free(p);
    return 1;
}

int isEmpty(LinkQueue Q)
{
    return Q.front->next == NULL;
    // return Q.front == Q.rear;
}

void showLinkQueue(LinkQueue Q)
{
    if (isEmpty(Q))
    {
        printf("showLinkQueue: Q is NULL\n");
        return;
    }
    LinkNode *p = Q.front->next;

    // 思路一：遍历到当前节点等于尾结点结束
    // int flag = 0; // 标记是否是尾节点
    // while (1)
    // {
    //     if (flag == 2)
    //         break;
    //     if (flag == 1)
    //         flag++;
    //     printf("%d%s", p->data, p->next == Q.rear ? "\n" : "->");
    //     p = p->next;
    //     if (p == Q.rear)
    //         flag++;
    // }

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
    Q->rear->next = p;
    Q->rear = p;
    return 1;
}

void initLinkQueue(LinkQueue *Q)
{
    // 创建头节点
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    if (p == NULL)
    {
        printf("initLinkQueue fail,case by: out of memory\n");
        exit(1);
    }
    // 头节点不存储数据
    p->data = 0;
    p->next = NULL;
    Q->front = Q->rear = p;
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

    enQueue(&Q, 123);
    showLinkQueue(Q);

    return 0;
}