#include <stdio.h>
#include <stdlib.h>
/**
 * 不带头结点的单项列表
 * @brief
 *
 * @return int
 */
typedef struct LNode
{
    int data;
    struct LNode *next;

} LNode, *LinkList;

LinkList createEmptyNode()
{
    LinkList list;
    list = (LNode *)malloc(sizeof(LNode));
    list->data = 0;
    list->next = NULL;
    return list;
}
int initLinkList(LinkList *L)
{
    LNode *p = (LNode *)malloc(sizeof(LNode));
    if (p == NULL)
    {
        printf("initLinkList fail,case by : out of memory\n");
        return 0;
    }
    p->data = 0;
    p->next = NULL;
    (*L) = p;
    return 1;
}

// 根据位序获取指定
LNode *getNodeBySeq(LinkList L, int i)
{
    if (i < 1)
    {
        printf("getElem fial, case by: i(%d) is illegal\n", i);
        return NULL;
    }
    LNode *p = L;
    int j = 1;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 根据元素获取指定节点
LNode *getNodeByElem(LinkList L, int elem)
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

int getLenght(LinkList L)
{
    LNode *p = L;
    int len = 0;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}
int isEmpty(LinkList L)
{
    return L == NULL;
}

// // 指定节点之前插入节点
// int insertBeforeNode(LNode *p, int elem)
// {
//     if (p == NULL)
//     {
//         printf("insertNextNode fail, caseby:p is NUll");
//         return 0;
//     }
//     LNode *q = (LNode *)malloc(sizeof(LNode));
//     if (q == NULL)
//     {
//         printf("insertNextNode fail, case by:out of memory\n");
//         return 0;
//     }
//     q->next = q->next;
//     q->next = q;
//     q->data = p->data;
//     p->data = elem;
//     return 1;
// }

// 删除指定节点的下一个节点
int delNextNode(LNode *p, int *delElem)
{
    if (p == NULL)
    {
        printf("delNextNode fail,case by: p is NULL\n");
        return 0;
    }
    LNode *q = p->next;
    if (q == NULL)
    {
        printf("delNextNode fail,case by: q is NULL\n");
        return 0;
    }
    *delElem = q->data;
    p->next = q->next;
    free(q);
    return 1;
}

// 无法删除最后一个节点
int delSpecifyNode(LNode *p)
{
    if (p == NULL)
    {
        printf("delSpecifyNode fail,case by:p is NULL\n");
        return 0;
    }
    LNode *q = p->next;
    if (q == NULL)
    {
        printf("delSpecifyNode fail,case by:q is NULL\n");
        return 0;
    }
    p->data = q->data; // 把后继节点数据复制到指定要删除的节点
    p->next = q->next; // 删除后继节点
    free(q);
    return 1;
}

int delNode(LinkList *L, int i, int *delElem)
{
    if (i < 1)
    {
        printf("delNode fail,case by: i(%d) is illegal\n", i);
        return 0;
    }
    if (isEmpty(*L))
    {
        printf("delNode fail, *L is NULL\n");
        return 0;
    }
    // 要删除的节点
    LNode *delNode;
    // 删除的是只有1个节点的链表
    if (i == 1 && getLenght(*L) == 1)
    {
        delNode = *L;
        *delElem = delNode->data;
        *L = NULL;
        free(delNode);
        return 1;
    }

    // 如果删除的是最后一个节点，且非第一个节点
    if (i != 1 && i == getLenght(*L))
    {
        // 1.获取删除节点的前一个节点
        // 2.删除节点
        return delNextNode(getNodeBySeq(*L, i - 1), delElem); // 注意 delNextNode 的第二个参数是一个int*（指针），此处不需要传 *delElem
    }
    // 删除链表长度大于1中的任意节点
    delNode = getNodeBySeq(*L, i);
    *delElem = delNode->data;
    return delSpecifyNode(delNode);
}
void showLinkList(LinkList L)
{
    if (isEmpty(L))
    {
        printf("showLinkList out:linkList is NULL\n");
    }
    LNode *p = L;
    while (p != NULL)
    {
        printf("%d%s", p->data, isEmpty(p->next) ? "\n" : "->");
        p = p->next;
    }
}

// 指定节点之后插入
int insertNextNode(LNode *p, int elem)
{
    if (p == NULL)
    {
        printf("fail:insertNextNode, caseby:p is NUll\n");
        return 0;
    }
    LNode *q = (LNode *)malloc(sizeof(LNode));
    if (q == NULL)
    {
        printf("insertNextNode fail, case by:out of memory\n");
        return 0;
    }
    q->data = elem;
    q->next = p->next;
    p->next = q;
    return 1;
}

int inserBeforeNode(LNode *p, int elem)
{
    if (p == NULL)
    {
        printf("inserBeforeNode fail,case by: p is NUll\n");
        return 0;
    }
    LNode *q = (LNode *)malloc(sizeof(LNode));
    if (q == NULL)
    {
        printf("inserBeforeNode fail, case by:out of memory\n");
        return 0;
    }
    q->next = p->next;
    p->next = q;
    q->data = p->data;
    p->data = elem;
    return 1;
}

int insertNode(LinkList *L, int i, int elem)
{

    if (i < 1)
    {
        printf("getElem fial, case by: i(%d) is illegal\n", i);
        return 0;
    }

    if (i == 1)
    {
        if (!isEmpty(*L))
            // 在不为空的链表中的第一个位置插入元素，则需要前插
            return inserBeforeNode(getNodeBySeq(*L, 1), elem);
        // 链表是空的，则需要创建一个空节点
        // initLinkList(L);
        // (*L)->data = elem;
        *L = createEmptyNode();
        (*L)->data = elem;
        return 1;
    }
    // 链表长度大于1，则可以获取插入节点位序的前一个节点，再用后插法插入节点
    return insertNextNode(getNodeBySeq(*L, i - 1), elem);
}

// 头插法建立不带头结点的双向列表
LinkList headInsert(LinkList *L)
{
    int sign = 0;
    printf("Tips:请在 > 之后输入节点元素,输入999退出程序\n");
    printf("> ");
    scanf("%d", &sign);
    while (sign != 999)
    {
        insertNode(L, 1, sign);
        printf("> ");
        scanf("%d", &sign);
    }
    showLinkList(*L);
    return *L;
}

// 尾插法
LinkList tailInsert(LinkList *L)
{
    int sign = 0;
    printf("Tips:请在 > 之后输入节点元素,输入999退出程序\n");
    printf("> ");
    scanf("%d", &sign);
    while (sign != 999)
    {
        insertNode(L, getLenght(*L) + 1, sign);
        printf("> ");
        scanf("%d", &sign);
    }
    showLinkList(*L);
    return *L;
}

int main()
{
    LinkList L = NULL;

    // headInsert(&L);
    tailInsert(&L);
    // showLinkList(L);
    // insertNode(&L, 1, 777);
    // showLinkList(L);

    // insertNode(&L, 1, 777);
    // showLinkList(L);
    // insertNode(&L, 2, 888);
    // showLinkList(L);
    // insertNode(&L, 4, 999);
    // showLinkList(L);
    // insertNode(&L, 6, 369); // fail
    // showLinkList(L);

    // int delElem = -1;
    // printf("%s%d\n", delNode(&L, getLenght(L), &delElem) ? "删除成功，删除节点数据为：" : "删除失败", delElem);
    // showLinkList(L);
    // delElem = -1;
    // printf("%s%d\n", delNode(&L, 2, &delElem) ? "删除成功，删除节点数据为：" : "删除失败 ", delElem);
    // showLinkList(L);
    // delElem = -1;
    // printf("%s%d\n", delNode(&L, 1, &delElem) ? "删除成功，删除节点数据为：" : "删除失败 ", delElem);
    // showLinkList(L);
    // delElem = -1;
    // printf("%s%d\n", delNode(&L, 1, &delElem) ? "删除成功，删除节点数据为：" : "删除失败 ", delElem);
    // showLinkList(L);
    // delElem = -1;
    // printf("%s%d\n", delNode(&L, 1, &delElem) ? "删除成功，删除节点数据为：" : "删除失败 ", delElem);
    // showLinkList(L);

    return 0;
}