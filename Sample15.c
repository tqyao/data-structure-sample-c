#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    int next;
};
typedef struct Node SLinkList[10];

int main()
{
    SLinkList L;
    printf("L -> %d\n", (int)sizeof(L));
    printf("SLinkList -> %d\n", (int)sizeof(SLinkList));

    // printf("L pointer -> %p\n", &L);
    // printf("SLinkList pointer -> %p\n", &SLinkList);//error

    SLinkList *p = &L;
    for (int i = 0; i < 10; i++)
    {
        p[i]->data = -2;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("data[%d] => %d\n", i, p[i]->data);
    }

    return 1;
}