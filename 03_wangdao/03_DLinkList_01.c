#include <stdio.h>
#include <stdlib.h>

// 带头节点的双向链表
typedef struct DNode // typedef:定义别名 数据类型:结构体 结构体名称:DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

// DLinkList initLinkList(DLinkList *L);
DLinkList initLinkList();
int isEmpty(DLinkList L);
int getLength(DLinkList L);
void showDLinkList(DLinkList L);
// int insertAfterNode(DLinkList *L, int elem);
int insertNextNode(DNode *p, DNode *s);
DNode *createEmptyNode();
DNode *getDNodeBySeq(DLinkList L, int i);
int delNextDNode(DNode *p);
void specifyNodeNextShow(DNode *p);
void specifyNodePriorShow(DNode *p);

// 指定节点前向遍历
void specifyNodePriorShow(DNode *p)
{
    if (p->data == 0) //不遍历头节点
    {
        printf("specifyNodePriorShow: p only head node\n");
        return;
    }
    DNode *x = p;
    while (p->prior != NULL)
    {
        printf("%d%s", p->data, p->prior->prior ? "->" : "\n");
        p = p->prior;
    }
}

// 给定节点后向遍历
void specifyNodeNextShow(DNode *p)
{
    if (p == NULL)
        printf("specifyNodeNextShow fail,case by:p is NULL\n");

    if (p->data == 0)
    {
        showDLinkList(p);
        return;
    }

    DNode *x = p;
    while (x != NULL)
    {
        printf("%d%s", x->data, x->next ? "->" : "\n");
        x = x->next;
    }
}

// 删除指定节点的后继节点
int delNextDNode(DNode *p)
{
    if (p == NULL)
    {
        printf("delNextDNode fail,case by:p is NULL\n");
        return 0;
    }
    DNode *q = p->next;
    if (q == NULL)
        return 1;

    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    return 1;
}

// 获取指定位序节点
DNode *getDNodeBySeq(DLinkList L, int i)
{
    if (getLength(L) <= 0)
        return NULL;
    DNode *p = L->next; //跳过头节点
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 创建空节点
DNode *createEmptyNode()
{
    DNode *p = (DNode *)malloc(sizeof(DNode));
    if (p == NULL)
    {
        printf("createEmptyNode fail,case by:p is NULL\n");
        exit(1);
    }
    p->data = 0;
    p->next = NULL;
    p->prior = NULL;
    return p;
}

int insertNextNode(DNode *p, DNode *s)
{
    if (p == NULL)
    {
        printf("insertAfterNode fial,case by:p is NULL\n");
        return 0;
    }
    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;

    p->next = s;
    s->prior = p;
    return 1;
}
// // 后插
// int insertAfterNode(DLinkList *L, int elem)
// {
//     if ((*L) == NULL)
//     {
//         *L = initLinkList();
//     }
//     DNode *s = (DNode *)malloc(sizeof(DNode));
//     if (s == NULL)
//     {
//         printf("insertAfterNode fail,case by:out of memory\n");
//         return 0;
//     }
//     s->data = elem;
//     s->next = (*L)->next;
//     if ((*L)->next != NULL)
//         (*L)->next->prior = s;
//     (*L)->next = s;
//     s->prior = (*L);
//     return 1;
// }

void showDLinkList(DLinkList L)
{
    if (getLength(L) <= 0)
    {
        printf("DLinkList is NULL\n");
        return;
    }
    DNode *p = L->next;
    while (p != NULL)
    {
        printf("%d%s", p->data, p->next == NULL ? "\n" : "->");
        p = p->next;
    }
}

int isEmpty(DLinkList L)
{
    return L == NULL;
}

int getLength(DLinkList L)
{
    int len = -1; //头结点不计算在长度内
    DNode *p = L;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

// 初始化
DLinkList initLinkList()
{
    DNode *p = (DNode *)malloc(sizeof(DNode)); // 初始化头节点
    if (p == NULL)
    {
        printf("initLinkList fail,case by:out of memory\n");
        return NULL;
    }
    p->next = NULL;
    p->prior = NULL;
    p->data = 0;
    return p;
}

// // 初始化
// int initLinkList(DLinkList *L)
// {
//     // 初始化头结点
//     (*L) = (DNode *)malloc(sizeof(DNode));
//     if (*L == NULL)
//     {
//         printf("initLinkList fail,case by:out of memory\n");
//         return 0;
//     }
//     (*L)->next = NULL;
//     (*L)->prior = NULL;
//     return 1;
// }

int main()
{
    DLinkList L = initLinkList();
    showDLinkList(L);
    DNode *n = createEmptyNode();
    n->data = 1;
    insertNextNode(L, n);
    showDLinkList(L);

    n = createEmptyNode();
    n->data = 2;
    insertNextNode(L, n);
    showDLinkList(L);

    DNode *n1 = createEmptyNode();
    n1->data = 333;
    n = getDNodeBySeq(L, 2);
    insertNextNode(n, n1);
    showDLinkList(L);

    DNode *n2 = getDNodeBySeq(L, 2);
    delNextDNode(n2);
    showDLinkList(L);

    delNextDNode(n2); // 下一个节点为空直接返回删除成功
    showDLinkList(L);

    DNode *n3 = createEmptyNode();
    n3->data = 777;
    insertNextNode(n, n3);
    showDLinkList(L);

    DNode *n4 = createEmptyNode();
    n4->data = 369;
    insertNextNode(n, n4);
    showDLinkList(L);

    specifyNodeNextShow(n);
    specifyNodeNextShow(L);

    printf("getLength(L) -> %d\n", getLength(L));
    specifyNodePriorShow(getDNodeBySeq(L, 4));
    specifyNodePriorShow(getDNodeBySeq(L, 1));

    return 0;
}