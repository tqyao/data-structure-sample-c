#include <stdio.h>
#include <stdlib.h>
// 双向循环链表
typedef struct DLNode
{
    int data;
    struct DLNode *next, *prior;
} DLNode, *DLinkList;

DLinkList initDLinkList();
int isEmpty(DLinkList L);
int insertNextNode(DLNode *p, DLNode *s);
int insertPriorNode(DLNode *p, DLNode *s);
void showDLinkList(DLNode *p);
DLNode *createEmptyNode();
int delSpecifyNode(DLNode *p);
int isHead(DLinkList L, DLNode *p);
int isTail(DLinkList L, DLNode *p);

int isTail(DLinkList L, DLNode *p)
{
    return p->next == L;
}

int isHead(DLinkList L, DLNode *p)
{
    return p->prior == L;
}

int delSpecifyNode(DLNode *p)
{
    if (isEmpty(p))
    {
        printf("delSpecifyNode fail, p only has head node\n");
        return 0;
    }
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return 1;
}
DLNode *createEmptyNode()
{
    DLNode *n = (DLNode *)malloc(sizeof(DLNode));
    if (n == NULL)
    {
        printf("createEmptyNode fail,case by:out of memory\n");
        exit(1);
    }
    n->data = 0;
    n->prior = NULL;
    n->next = NULL;
    return n;
}
void showDLinkList(DLNode *p)
{
    if (isEmpty(p))
    {
        printf("showDLinkList:p is NULL\n");
        return;
    }
    // DLNode *x = p->next;
    DLNode *x = p;
    int first = 1;
    while (1)
    {
        if (x->data != 0)
            printf("%s<-%d->", first-- ? "->" : "", x->data);
        x = x->next;
        if (x == p)
            break;
    }
    printf("<-\n");
}

int insertPriorNode(DLNode *p, DLNode *s)
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

    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return 1;
}

int insertNextNode(DLNode *p, DLNode *s)
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
    p->next->prior = s;
    p->next = s;
    s->prior = p;
    return 1;
}

int isEmpty(DLinkList L)
{
    return L->next == L && L->prior == L;
}

DLinkList initDLinkList()
{
    DLinkList L = (DLinkList)malloc(sizeof(DLNode));
    if (L == NULL)
    {
        printf("initDLinkList fail,case by : out of memory\n");
        return 0;
    }
    L->data = 0;
    L->next = L;
    L->prior = L;
    return L;
}

int main()
{
    DLinkList L = initDLinkList();

    showDLinkList(L);
    DLNode *n1 = createEmptyNode();
    n1->data = 111;
    insertNextNode(L, n1);
    showDLinkList(L);

    DLNode *n2 = createEmptyNode();
    n2->data = 222;
    insertNextNode(L, n2);
    showDLinkList(L);

    DLNode *n3 = createEmptyNode();
    n3->data = 333;
    insertPriorNode(L, n3);
    showDLinkList(L);

    printf("isHead(L,L) -> %d\n", isHead(L, L->next));
    printf("isTail(L,n1) -> %d\n", isTail(L, n1));

    delSpecifyNode(n3);
    showDLinkList(L);

    delSpecifyNode(n1);
    showDLinkList(L);

    delSpecifyNode(n2);
    showDLinkList(L);

    // delSpecifyNode(n2);
    // showDLinkList(L);

    return 0;
}