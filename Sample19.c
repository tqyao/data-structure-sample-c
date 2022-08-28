#include <stdio.h>
#include <stdlib.h>
/**
 * @brief
 * 带头节点的链式栈：
 * 探讨 typedef LinkNode 与 *LinkNode 的区别
 */
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LinkNode;

int isEmpty(LinkNode S)
{
    return S.next == NULL;
}

// 此处的 S 与 参数调用时的 S 是两个截然不同实例，此处的形参是实参的深拷贝，因此改变
int push(LinkNode S, int elem)
{
    printf("push S addresss => %p\n", &S); // 与main中不同（由于拷贝）
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    if (p == NULL)
    {
        printf("push fail, case by: out of memery\n");
        return 0;
    }
    p->data = elem;
    p->next = S.next;
    printf("push S.next value => %p\n", S.next);         //与main中的相同，值拷贝
    printf("push S.next 's address => %p\n", &(S.next)); //与main中不同，由于是结构体拷贝，内存空间不同
    S.next = p;
    return 1;
}

void showLinkList(LinkNode S)
{
    if (isEmpty(S))
    {
        printf("showLinkList: S is NULL\n");
        return;
    }
    /**********************************/
    // 指针遍历
    LinkNode *p = S.next;
    while (p != NULL)
    {
        printf("%d%s", p->data, p->next ? "->" : "\n");
        p = p->next;
    }
    /**********************************/
    /**********************************/

    // 实例遍历
    // LinkNode p = *(S.next);  //error

    /**********************************/
}

/**
 * @brief
 * 初始化头结点
 *
 * @return LinkNode*
 */
LinkNode *initLinkNode()
{
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    if (p == NULL)
    {
        printf("initLinkNode fail,case by:out of memery\n");
        exit(1);
    }
    p->data = 0;
    p->next = NULL;
    return p;
}

int main()
{
    LinkNode *S = initLinkNode();
    showLinkList(*S);
    printf("main S addresss => %p\n", S);
    printf("main S->next value => %p\n", S->next);
    printf("main S->next 's address => %p\n", &(S->next));
    push(*S, 777);
    showLinkList(*S);
    return 0;
}