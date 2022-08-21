#include <stdio.h>
#include <stdlib.h>

// 循环单向链表
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

LinkList initLinkList();
int isEmpty(LinkList L);
int isTail(LinkList L, LNode *p);
int insertNextNode(LNode *p, LNode *s);
void showLinkList(LNode *p);
LNode *createEmptyNode();
int insertPriorNode(LNode *p, LNode *s);
int delSpecifyNode(LNode *p);
LNode *getPriorOfSpecifyNode(LNode *p);
int insertLNodeByTailPointer(LNode **tail, LNode *s);

int insertLNodeByTailPointer(LNode **tail, LNode *s)
{
    // printf("calling  => %p\n", &tail);
    if (*tail == NULL)
    {
        printf("insertLNodeByTailPoint faiul,case by : tail pointer is NULL\n");
        return 0;
    }

    if (s == NULL)
    {
        printf("insertLNodeByTailPoint faiul,case by : s is NULL\n");
        return 0;
    }
    s->next = (*tail)->next;
    (*tail)->next = s;
    (*tail) = s;
    return 1;
}

// 获取指定节点的前驱节点
LNode *getPriorOfSpecifyNode(LNode *p)
{
    LNode *x = p;
    while (x->next != p)
        x = x->next;
    return x;
}

int delSpecifyNode(LNode *p)
{
    if (p == NULL)
    {
        printf("delSpecifyNode fail,case by:p is NULL\n");
        return 0;
    }
    if (p->data == 0) // 头节点不能删
    {
        printf("delSpecifyNode fail,case by:head node cant del\n");
        return 0;
    }
    // 获取单向循环链表要删除节点的前一个节点
    LNode *q = getPriorOfSpecifyNode(p);
    q->next = p->next;
    free(p);
    return 1;
}

// 单向链表指定节点之前插入节点
int insertPriorNode(LNode *p, LNode *s)
{
    if (p == NULL)
    {
        printf("insertPriorNode faiul,case by : p is NULL\n");
        return 0;
    }

    if (s == NULL)
    {
        printf("insertPriorNode faiul,case by : s is NULL\n");
        return 0;
    }

    LNode *x = p; // 指针x
    // 遍历单向循环链表找到要插入节点p的前一个节点
    while (x->next != p)
        x = x->next;
    s->next = x->next;
    x->next = s;
    return 1;
}

LNode *createEmptyNode()
{
    LNode *n = (LNode *)malloc(sizeof(LNode));
    if (n == NULL)
    {
        printf("createEmptyNode fail,case by:out of memory\n");
        exit(1);
    }
    n->data = 0;
    n->next = NULL;
    return n;
}

// 给定节点遍历全表
void showLinkList(LNode *p)
{
    if (isEmpty(p))
    {
        printf("p only has head node\n");
        return;
    }
    LNode *x = p;
    while (1)
    {
        if (x->data != 0)                                        // 头结点不存储数据不输入
            printf("->%d%s", x->data, x->next == p ? "->" : ""); // 最后一个节点输出多输出一个 ->
        else if (x->next == p)                                   // 如果恰好头节点是p的前驱节点，上面的if会不满足条件无法输出 ->,所以这里再判断一下
            printf("->");
        x = x->next;
        if (x == p)
            break;
    }
    printf("\n");
}

// 指定节点之后插入节点
int insertNextNode(LNode *p, LNode *s)
{
    if (p == NULL)
    {
        printf("insertNextNode faiul,case by : p is NULL\n");
        return 0;
    }

    if (s == NULL)
    {
        printf("insertNextNode faiul,case by : s is NULL\n");
        return 0;
    }

    s->next = p->next;
    p->next = s;
    return 1;
}

// 判断p节点是否为表尾节点
int isTail(LinkList L, LNode *p)
{
    return p->next == (struct LNode *)L;
}
int isEmpty(LinkList L)
{
    return L->next == (struct LNode *)L;
}
LinkList initLinkList()
{
    LinkList L = (LinkList)malloc(sizeof(LNode));
    if (L == NULL)
    {
        printf("initLinkList fail,case by:out of memory\n");
        exit(1);
    }

    L->data = 0;
    L->next = (struct LNode *)L;
    return L;
}

int main()
{
    LinkList L = initLinkList();
    printf("isEmpty(L) -> %d\n", isEmpty(L));

    showLinkList(L);
    LNode *n1 = createEmptyNode();
    n1->data = 789;
    insertNextNode(L, n1);
    showLinkList(L);

    LNode *n2 = createEmptyNode();
    n2->data = 111;
    insertNextNode(L, n2);
    showLinkList(L);

    LNode *n3 = createEmptyNode();
    n3->data = 333;
    insertNextNode(L, n3);
    showLinkList(L);

    LNode *n4 = createEmptyNode();
    n4->data = 555;
    insertPriorNode(L, n4);
    showLinkList(L);

    printf("getPriorOfSpecifyNode(L)->data:%d\n", getPriorOfSpecifyNode(L)->data);
    showLinkList(L);
    delSpecifyNode(n4);
    showLinkList(L);

    showLinkList(L);
    delSpecifyNode(n2);
    showLinkList(L);

    LNode *tail = initLinkList();

    LNode *n5 = createEmptyNode();
    n5->data = 666;
    // printf("call before => %p\n", &L2);
    insertLNodeByTailPointer(&tail, n5);
    // printf("call after => %p\n", &L2);
    showLinkList(tail);

    LNode *n6 = createEmptyNode();
    n6->data = 888;
    insertLNodeByTailPointer(&tail, n6);
    showLinkList(tail); // showLinkList(tail) 会先输出尾节点元素值
    return 0;
}