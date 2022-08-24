#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
//静态链表 定义方式一
typedef struct
{
    int data;
    // 游标
    int next;

} SLinkList[MAXSIZE];
// ----------------

//静态链表 定义方式二
struct Node
{
    int data;
    int next;
};
typedef struct Node NodeList[MAXSIZE];
// ----------------

typedef struct Node02
{
    int data;
    int next;
} Nd;

typedef struct
{
    int data;
} Test;

struct
{
    int data;
} test01;

int main()
{

    struct Node x;
    Nd n;
    Test t;
    printf("n ->%p\n", &n);
    printf("x -> %p\n", &x);
    printf("t -> %p\n", &t);
    printf("test01 -> %p\n", &test01); // !!! 没有报错
    // printf("nd ->%p\n", &Nd); // error
    // printf("Node address ->%p", &Node); //error

    printf("Node ->%d\n", (int)(sizeof(x)));
    printf("n ->%d\n", (int)(sizeof(n)));
    printf("nd ->%d\n", (int)(sizeof(Nd)));
    printf("NodeList ->%d\n", (int)(sizeof(NodeList)));
    printf("SLinkList ->%d\n", (int)(sizeof(SLinkList)));

    return 1;
}