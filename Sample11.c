#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;

} LNode, *LinkList;

void test01(LNode *node)
{
    // node = (LNode *)malloc(sizeof(LNode *));
    // node->next = NULL;
    node->data = 777;
}
void test02(LinkList *list)
{
    // (*list)->data = 777;
    *list = (LNode *)malloc(sizeof(LNode *));
    // list = (LNode *)malloc(sizeof(LNode *));
    // (*list)->data = 777;
}
void test03(LinkList *L)
{
}
int main02()
{
    // LNode *node;
    // printf("%d\n", node->data);
    // test01(node);
    // printf("%d\n", node->data);

    LinkList *list;
    // printf("%d\n", (*list)->data);
    // printf("%p\n", (LNode *)malloc(sizeof(LNode *)));
    *list = (LinkList)malloc(sizeof(LNode));

    // printf("%d\n", (**list).data);
    // printf("%d\n", (*list)->data);

    // test02(list);
    // printf("%d\n", (*list)->data);
}