#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
//静态链表 定义方式一
typedef struct Node
{
    int data;
    // 游标
    int cur;

} SLinkList[MAXSIZE];
SLinkList *initSLinkList();
int insertNodeTail(SLinkList *L, int elem);
void showSLinkList(SLinkList *L);
int isEmpty(SLinkList *L);
int getLength(SLinkList *L);
int insertNodeBySeq(SLinkList *L, int i, int elem);
int findLeisureNode(SLinkList *L);
int findNodeBySeq(SLinkList *L, int i);

// 通过节点位序查找节点，返回索引
int findNodeBySeq(SLinkList *L, int i)
{
    if (i < 1)
    {
        printf("findNodeBySeq fail,case by: i is must gt 0\n");
        return 0;
    }
    SLinkList *p = L;
    for (int j = 1; j < i; j++) //迭代到指定位序i的前一个位序节点，也就是节点位序 i-1 ，其游标正式要查找位序的索引
    {
        if ((*p)->cur == -1)
        {
            printf("findNodeBySeq fail,case by : i is cross the border\n");
            return 0;
        }
        p = L + (*p)->cur;
    }
    return (*p)->cur;
}

// 查找空闲节点，返回节点索引
int findLeisureNode(SLinkList *L)
{
    for (int i = 1; i < MAXSIZE; i++)
        if (L[i]->cur == -2)
            return i;
    return 0;
}

/**
 * @brief
 * 根据位序插入节点
 * @param L
 * @param i
 * @param elem
 * @return int 成功/失败
 */
int insertNodeBySeq(SLinkList *L, int i, int elem)
{
    // 判断插入位序是否合法
    if (i < 1 || i > getLength(L) + 1)
    {
        printf("insertNodeBySeq fail,case by : i(%d) is illegel\n", i);
        return 0;
    }

    // 查找空闲节点，不存在提示并退出
    int leisureNodeIdx = findLeisureNode(L);
    if (!leisureNodeIdx)
    {
        printf("insertNodeBySeq fail,case by: SLinkList is full\n");
        return 0;
    }

    // 判断是否尾部插入
    // - 是
    // 调用尾插函数
    if (i == getLength(L) + 1)
        return insertNodeTail(L, elem);

    // - 否
    // 查找插入节点位序的前一个节点，保存该节点指针域，修改该节点指针域指向空闲节点，修改空闲节点指针区域指向上一个节点保存的指针域
    int priorNodeIdx = findNodeBySeq(L, i - 1);
    L[leisureNodeIdx]->cur = L[priorNodeIdx]->cur;
    L[leisureNodeIdx]->data = elem;
    L[priorNodeIdx]->cur = leisureNodeIdx;
    return 1;
}

// 静态链表尾部插入
int insertNodeTail(SLinkList *L, int elem)
{
    // 找到空闲节点位序
    int seq = 0;
    for (int j = 1; j < MAXSIZE; j++)
    {
        if (L[j]->cur == -2)
        {
            seq = j;
            L[j]->data = elem;
            L[j]->cur = -1; // 插入节点标记为尾结点
            break;
        }
    }

    if (!seq)
    {
        printf("insertNodeBySeq fail,case by : List is full\n");
        return 0;
    }

    SLinkList *p = L;
    while (1)
    {
        // 找到尾节点
        if ((*p)->cur == -1)
            break;
        p = L + (*p)->cur;
    }
    // 尾结点指向新的空闲节点
    (*p)->cur = seq;
    return 1;
}

int isEmpty(SLinkList *L)
{
    return (*L)->cur == -1;
}

int getLength(SLinkList *L)
{
    int len = 0;
    // 遍历L的指针
    SLinkList *p = L;
    while ((*p)->cur != -1)
    {
        len++;
        p = L + (*p)->cur;
    }
    return len;
}

void showSLinkList(SLinkList *L)
{
    if (isEmpty(L))
    {
        printf("showSLinkList:L is NULL\n");
        return;
    }

    SLinkList *p = L + (*L)->cur;
    while (1)
    {
        printf("%d", (*p)->data);
        p = L + (*p)->cur;
        if ((*p)->cur == -1)
        {
            printf("\n");
            break;
        }
        printf("->");
    }
}

SLinkList *initSLinkList()
{
    //静态链表首节点地址
    // SLinkList *L = (SLinkList *)malloc(MAXSIZE * 8);
    // SLinkList *L = (SLinkList)malloc(MAXSIZE * (sizeof(struct Node))); // error
    SLinkList *L = (SLinkList *)malloc(MAXSIZE * (sizeof(struct Node)));
    //初始化游标
    for (int i = 1; i < MAXSIZE; i++)
        L[i]->cur = -2; //-2表示为空闲节点
    // 标记首地址元素节点为头节点,-1表示为节点末尾
    L[0]->cur = -1;
    L[0]->data = 0;
    return L;
}

int main()
{
    // SLinkList L;
    // printf("L -> %p\n", L);
    // printf("sizeof L -> %d\n", (int)sizeof(L));                 // 80
    // printf("sizeof SLinkList -> %d\n", (int)sizeof(SLinkList)); // 80
    // // printf("SLinkList - >%p", &SLinkList);//error
    // // printf("Node -> %d\n", (int)sizeof(struct Node n));//error
    // struct Node n;
    // printf("Node -> %d\n", (int)sizeof(n)); // error

    SLinkList *L = initSLinkList();
    showSLinkList(L);
    printf("空闲节点索引:%d\n", findLeisureNode(L));

    insertNodeTail(L, 777);
    showSLinkList(L);

    insertNodeBySeq(L, 2, 888);
    showSLinkList(L);

    return 1;
}