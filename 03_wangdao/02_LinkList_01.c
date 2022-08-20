#include <stdio.h>
#include <stdlib.h>
/**
 * 带头结点单项链表
 * @brief
 *
 * @return int
 */
typedef struct LNode
{
    int data;
    struct LNode *next;

} LNode, *LinkList;

// int initLinkList(LNode *L);
// LinkList initLinkList(LNode *L);

// int insertNode(LinkList list, int i, int elem);
// void showLinkList(LinkList list);
// int isEmpty(LinkList list);

// LinkList initLinkList()
// {
//     LinkList *L;
//     (*L) = (LinkList)malloc(sizeof(LNode));
//     (*L)->next = NULL;
//     (*L)->data = 0;
//     return L;
// }

// 初始化
LinkList initLinkList()
{
    LinkList L;
    L = (LinkList)malloc(sizeof(LNode));
    if (L == NULL)
    {
        printf("initLinkList fail, case by:out of memory\n");
        exit(1);
    }
    L->data = 0;
    L->next = NULL;
    return L;
}

// 获取带头节点的指定位序节点
LNode *getElem(LinkList list, int i)
{
    if (i < 0)
    {
        printf("getElem fial, case by: i(%d) is illegal\n", i);
        return NULL;
    }
    LNode *p = list;
    int j = 0; // 当前p指针所在节点位序
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

LNode *locateElem(LinkList L, int elem)
{
    LNode *p = L;
    while (p != NULL)
    {
        if (p->data == elem)
            break;
        p = p->next;
    }
    return p;
}

int length(LinkList L)
{
    int count = -1;
    LNode *p = L;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}

// 指定节点插入前驱节点
int insertPriorNode(LNode *p, int elem)
{
    if (p == NULL)
    {
        printf("insertPriorNode fail, case by: *p is NULL\n");
        return 0;
    }

    if (p->data == 0) // 不能在头节点之前插入
    {
        printf("insertPriorNode fail, case by: head node can not insertPriorNode\n");
        return 0;
    }
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    if (newNode == NULL)
    {
        printf("insertNextNode fail, case by:out of memory\n");
        return 0;
    }
    newNode->next = p->next;
    p->next = newNode;
    newNode->data = p->data;
    p->data = elem;
    return 1;
}
// 指定节点插入后继节点
int insertNextNode(LNode *p, int elem)
{
    if (p == NULL)
    {
        printf("insertNextNode fail, case by: *p is NULL\n");
        return 0;
    }
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    if (newNode == NULL)
    {
        printf("insertNextNode fail, case by:out of memory\n");
        return 0;
    }
    newNode->data = elem;
    newNode->next = p->next;
    p->next = newNode;
    return 1;
}
// 按位序插入
int insertNode(LinkList list, int i, int elem)
{

    // // 1. 找到位序 i 的前一个节点
    // LNode *nodePoint = list; //指向链表指针
    // int j = 0;               // 记录指针所处节点位序

    // // 从第一个节点开始，也就是从节点位序 1 元素 遍历 i - 1 次找到 i 的前一个节点
    // // 这里我们是带头节点的，第一个节点不储存数据，标记为0，所以 j - 2 为 i 节点的前一个节点
    // while (nodePoint != NULL && j < i - 1)
    // {
    //     // 找到位序 i 的前一个节点
    //     nodePoint = nodePoint->next;
    //     j++;
    // }

    // // i 不合法，插入失败
    // if (i < 1 || nodePoint == NULL)
    // {
    //     printf("insert fial, case by: i(%d) is illegal\n", i);
    //     return 0;
    // }

    // // 2. 插入节点
    // LNode *newNode = (LNode *)malloc(sizeof(LNode *));
    // newNode->data = elem;
    // newNode->next = nodePoint->next;
    // nodePoint->next = newNode;

    if (i < 1)
    {
        printf("insert fial, case by: i(%d) is illegal\n", i);
        return 0;
    }
    return insertNextNode(getElem(list, i - 1), elem);
    // return insertNextNode(getElem(list, i), elem);
    // return insertNextNode(getElem(list, i - 1), elem);
}
// 删除指定节点
int delSpecifyNode(LNode *p)
{
    if (p == NULL)
    {
        printf("delPriorNode fail, case by: *p is NULL\n");
        return 0;
    }
    if (p->data == 0) // 不许删除头节点
    {
        printf("delPriorNode fail, case by: head can not del\n");
        return 0;
    }

    LNode *q = p->next;
    if (q == NULL) // 删除的是最后一个节点,无法删除
    {
        printf("warn:delSpecifyNode fail, case by: Unable to delete the last node");
        return 0;
    }
    p->data = q->data;
    p->next = q->next;
    free(q);
    return 1;
}
// 删除指定节点后继节点
int delNextNode(LNode *p, int *elem)
{
    if (p == NULL)
    {
        printf("delNextNode fail, case by: *p is NULL\n");
        return 0;
    }
    LNode *delNode = p->next;
    if (delNode == NULL)
    {
        printf("delNextNode fail, case by: p->next is NULL\n");
        return 0;
    }

    *elem = delNode->data;
    p->next = delNode->next;
    free(delNode);
    return 1;
}

// 按位序删除节点
int delNode(LinkList list, int i, int *delElem)
{

    // if (i < 1)
    // {
    //     printf("delNode fial, case by: i(%d) is illegal\n", i);
    //     return 0;
    // }

    // LNode *nodePoint = list;               // nodePoint 指向的是头结点，不存储数据，也就是第0个节点
    // int j = 0;                             //当前 nodePoint 指向的是第几个节点
    // while (nodePoint != NULL && j < i - 1) // 找到删除节点的前一个节点
    // {
    //     nodePoint = nodePoint->next;
    //     j++;
    // }
    // LNode *delNode = nodePoint->next;

    // if (i < 1 || delNode == NULL) // 要删除的节点是否存在
    // {
    //     printf("delNode fial, case by: i(%d) is illegal\n", i);
    //     return 0;
    // }

    // *delElem = delNode->data;
    // nodePoint->next = delNode->next;
    // free(delNode); // 释放删除节点内存

    // return delNextNode(delNode, delElem);
    return delNextNode(getElem(list, i - 1), delElem);
}

int isEmpty(LinkList list)
{
    return list == NULL;
}

void showLinkList(LinkList list)
{
    LNode *nodePoint = list->next;
    if (isEmpty(nodePoint))
        printf("linkList is NULL\n");
    while (nodePoint != NULL)
    {
        // printf("%d ", nodePoint->data);
        printf("%d%s", nodePoint->data, nodePoint->next ? "->" : "\n");
        nodePoint = nodePoint->next;
    }
}

LinkList headInsert(LinkList *L)
{
    // 创建表头节点
    (*L) = (LNode *)malloc(sizeof(LNode));
    if (*L == NULL)
    {
        printf("headInsert fail,case by:out of memerty\n");
        return 0;
    }
    (*L)->data = 0;
    (*L)->next = NULL;

    int sign = 0;
    printf("Tips:请在 > 之后输入节点元素,输入999退出程序\n");
    printf("> ");
    scanf("%d", &sign);
    while (sign != 999)
    {
        insertNode(*L, 1, sign);
        printf("> ");
        scanf("%d", &sign);
    }
    showLinkList(*L);
    return *L;
}
// 带头节点尾插法创建链表
LinkList tailInsert(LinkList *L)
{
    // 创建头节点
    (*L) = initLinkList();
    int sign = 0;
    printf("Tips:请在 > 之后输入节点元素,输入999退出程序\n");
    printf("> ");
    scanf("%d", &sign);
    while (sign != 999)
    {
        insertNode(*L, length(*L) + 1, sign);
        printf("> ");
        scanf("%d", &sign);
    }
    showLinkList(*L);
    return *L;
}

int main()
{

    LinkList L;
    // L = headInsert(&L);
    L = tailInsert(&L);
    showLinkList(L);

    // LinkList list = initLinkList();
    // printf("1point -> %p\n", &list);

    // showLinkList(list);
    // insertNode(list, 1, 777);
    // printf("3point -> %p\n", &list);

    // showLinkList(list);
    // insertNode(list, 1, 999);
    // showLinkList(list);
    // insertNode(list, 3, 369);
    // showLinkList(list);
    // // insertNode(list, 5, 957);
    // insertNode(list, -1, 2233);
    // showLinkList(list);

    // int delElem = -1;
    // printf("%s, del value:%d\n", delNode(list, 1, &delElem) ? "删除成功" : "删除失败", delElem);
    // showLinkList(list);
    // delElem = -1;
    // printf("%s, del value:%d\n", delNode(list, 3, &delElem) ? "删除成功" : "删除失败", delElem);
    // showLinkList(list);
    // delElem = -1;
    // printf("%s, del value:%d\n", delNode(list, -1, &delElem) ? "删除成功" : "删除失败", delElem);
    // showLinkList(list);

    // insertNode(list, 1, 444);
    // showLinkList(list);
    // insertNextNode(list, 666);

    // showLinkList(list);
    // insertPriorNode(list, 790);
    // showLinkList(list);

    // delElem = -1;
    // printf("%s, del value:%d\n", delNode(list, length(list), &delElem) ? "删除成功" : "删除失败", delElem);
    // showLinkList(list);
    // delElem = -1;
    // printf("%s, del value:%d\n", delNextNode(list, &delElem) ? "删除成功" : "删除失败", delElem);
    // delElem = -1;
    // showLinkList(list);
    // printf("%s\n", delSpecifyNode(list) ? "删除成功" : "删除失败");
    // showLinkList(list);

    // // printf("%d\n", getElem(list, 3)->data);
    // insertNextNode(getElem(list, 2), 1000);
    // showLinkList(list);
    // insertPriorNode(getElem(list, 2), 2000);
    // showLinkList(list);
    // insertNextNode(getElem(list, length(list)), 3000);
    // showLinkList(list);

    // insertNextNode(getElem(list, 0), 4000);
    // showLinkList(list);

    // delElem = -1;
    // printf("%s, del value:%d\n", delNextNode(getElem(list, length(list)), &delElem) ? "删除成功" : "删除失败", delElem);
    // showLinkList(list);

    return 0;
}
