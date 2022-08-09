#include <stdio.h>

#define MAXSIZE 10

typedef struct
{
    int data[MAXSIZE];
    int lenght;
} SqList;

void initList(SqList *list);
void destoryList(SqList *list);
int listInsert(SqList *list, int i, int elem);
int listDelete(SqList *list, int i, int *elem);
int getElem(SqList list, int i);
int locateElem(SqList list, int elem);

void printList(SqList list);
int getLen(SqList list);
int isEmpty(SqList list);
int main()
{
    SqList list;
    initList(&list);
    printList(list);
    printf("%s\n", listInsert(&list, 1, 10) ? "插入成功" : "插入失败");
    printf("%s\n", listInsert(&list, 1, 11) ? "插入成功" : "插入失败");
    printf("%s\n", listInsert(&list, 1, 12) ? "插入成功" : "插入失败");
    printList(list);

    int delElem;
    printf("%s\n", listDelete(&list, 1, &delElem) ? "删除成功" : "删除失败");
    printf("%s\n", listDelete(&list, 10, &delElem) ? "删除成功" : "删除失败");
    printf("%s\n", listDelete(&list, list.lenght, &delElem) ? "删除成功" : "删除失败");
    printf("%s\n", listDelete(&list, 0, &delElem) ? "删除成功" : "删除失败");
    printf("%s\n", listDelete(&list, 1, &delElem) ? "删除成功" : "删除失败");
    printList(list);

    printf("%s\n", listInsert(&list, 1, 100) ? "插入成功" : "插入失败");
    printf("%s\n", listInsert(&list, 1, 101) ? "插入成功" : "插入失败");
    printf("%d\n", getElem(list, 2));

    printList(list);
    printf("%d的位序为%d\n", 101, locateElem(list, 101));

    printf("%s\n", listInsert(&list, 1, 10) ? "插入成功" : "插入失败");
    printf("%s\n", listInsert(&list, 1, 10) ? "插入成功" : "插入失败");
    printf("%s\n", listInsert(&list, 1, 10) ? "插入成功" : "插入失败");
    printf("%s\n", listInsert(&list, 1, 10) ? "插入成功" : "插入失败");
    printf("%s\n", listInsert(&list, 1, 10) ? "插入成功" : "插入失败");
    printf("%s\n", listInsert(&list, 1, 10) ? "插入成功" : "插入失败");
    printf("%s\n", listInsert(&list, 1, 10) ? "插入成功" : "插入失败");
    printf("%s\n", listInsert(&list, 1, 10) ? "插入成功" : "插入失败");
    printf("%s\n", listInsert(&list, 1, 10) ? "插入成功" : "插入失败"); //数组容量满了无法插入

    printList(list);
    return 0;
}

int locateElem(SqList list, int elem)
{
    for (int i = 0; i < list.lenght; i++)
        if (list.data[i] == elem)
            return i + 1;
    return 0;
}
int getElem(SqList list, int i)
{
    if (i < 1 || i > list.lenght)
    {
        return 0;
    }
    return list.data[i - 1];
}
int isEmpty(SqList list)
{
    return getLen(list) <= 0;
}

int getLen(SqList list)
{
    return list.lenght;
}

void printList(SqList list)
{
    if (isEmpty(list))
    {
        printf("list 是空的\n");
        return;
    }
    for (int i = 0; i < list.lenght; i++)
        printf("%d%c", list.data[i], i == list.lenght - 1 ? '\n' : ' ');

    return;
}

int listInsert(SqList *list, int i, int elem)
{
    if (i < 1 || i > list->lenght + 1)
        return 0;
    if (list->lenght == MAXSIZE) // 满了
    {
        printf("数组容量到大极限\n");
        return 0;
    }

    for (int j = list->lenght; j >= i; j--)
        list->data[j] = list->data[j - 1];

    list->data[i - 1] = elem;
    list->lenght++;
    return 1;
}
int listDelete(SqList *list, int i, int *elem)
{
    if (i < 1 || i > list->lenght)
        return 0;

    *elem = list->data[i - 1]; //‘取回’删除该位序的元素值
    // for (int j = i + 1; i <= list->lenght; j++) //删除位序为 3 的元素，则位序3以后到length的元素都需要往前移动1位
    //     list->data[j - 2] = list->data[j - 1];

    // 从第i个位序开始，i （不包括i）往后的元素都要向前移动1位（i+1），但这里j是从i开始，相应的到lenght-1结束
    for (int j = i; j < list->lenght; j++)
        list->data[j - 1] = list->data[j];
    list->lenght--;
    return 1;
}

void initList(SqList *list)
{
    list->lenght = 0;
}