#include <stdio.h>
#include <stdlib.h>
#define INITSIZE 5

typedef struct
{
    int *data;
    int maxSize;
    int lenght;

} SqList;

void capacity(SqList *list);

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

    // 测试扩容
    // printf("%d\n", list.maxSize);
    // capacity(&list);
    // printf("%d\n", list.maxSize);

    printList(list);
    printf("%s\n", listInsert(&list, 1, 10) ? "插入成功" : "插入失败");
    printf("%s\n", listInsert(&list, 1, 11) ? "插入成功" : "插入失败");
    printf("%s\n", listInsert(&list, 1, 12) ? "插入成功" : "插入失败");
    printf("%s\n", listInsert(&list, 1, 13) ? "插入成功" : "插入失败");
    printf("%s\n", listInsert(&list, 1, 14) ? "插入成功" : "插入失败");
    printf("%s\n", listInsert(&list, 1, 15) ? "插入成功" : "插入失败");
    printf("%s\n", listInsert(&list, 1, 16) ? "插入成功" : "插入失败");
    printf("数组最大容量:%d\n", list.maxSize);
    printf("数组当前长度:%d\n", list.lenght);
    printf("%s\n", listInsert(&list, 8, 17) ? "插入成功" : "插入失败");
    printf("数组最大容量:%d\n", list.maxSize);
    printf("数组当前长度:%d\n", list.lenght);
    printf("%s\n", listInsert(&list, 10, 18) ? "插入成功" : "插入失败");
    printf("%s\n", listInsert(&list, 0, 18) ? "插入成功" : "插入失败");
    printList(list);

    int delElem;
    printf("%s\n", listDelete(&list, 1, &delElem) ? "删除成功" : "删除失败");
    printf("删除元素值：%d\n", delElem);
    printList(list);
    printf("%s\n", listDelete(&list, list.lenght, &delElem) ? "删除成功" : "删除失败");
    printf("删除元素值：%d\n", delElem);
    printList(list);

    printf("获取位序2的元素:%d\n", getElem(list, 2));
    printf("获取位序等同于数组长度的元素:%d\n", getElem(list, list.lenght));
    printf("不合法的位序元素获取:%d\n", getElem(list, list.lenght + 1));

    printList(list);
    printf("获取指定元素:%d的索引:%d\n", 3, locateElem(list, 3));
    printf("获取指定元素:%d 的索引:%d\n", 11, locateElem(list, 11));

    // destoryList(&list);

    return 0;
}
void capacity(SqList *list)
{
    // 拿到旧数组引用，以便拷贝和销毁
    int *oldData = list->data;
    // +5 容量，更新容量记录
    list->data = (int *)malloc((list->maxSize += 5) * sizeof(int));
    for (int i = 0; i < list->lenght; i++)
        list->data[i] = oldData[i];
    free(oldData); // 释放
}
void initList(SqList *list)
{
    list->data = (int *)malloc(INITSIZE * sizeof(int));
    list->lenght = 0;
    list->maxSize = INITSIZE;
}

int listInsert(SqList *list, int i, int elem)
{
    if (i < 1 || i > list->lenght + 1) // 位序从1开始，1<=i<=length+1
        return 0;
    if (list->lenght == list->maxSize) // 元素长度等于数组最大容量：已满，需要扩容
        capacity(list);
    for (int j = list->lenght; j >= i; j--) // i 以及i后的元素都需要移动，移动元素个数：lenght - i + 1;
        list->data[j] = list->data[j - 1];
    list->data[i - 1] = elem;
    list->lenght++;
    return 1;
}
int listDelete(SqList *list, int i, int *elem)
{
    if (i < 1 || i > list->lenght)
        return 0;
    *elem = list->data[i - 1];
    for (int j = i; j < list->lenght; j++) // 删除要移动 lenght - i 个元素，即 (i+1) ~ lenght 或 i ~ length - 1；
        list->data[j - 1] = list->data[j];
    list->lenght--;
    return 1;
}

int getElem(SqList list, int i)
{
    if (i < 1 || i > list.lenght)
    {
        printf("位序不合法\n");
        return 0;
    }
    return list.data[i - 1];
}

int locateElem(SqList list, int elem)
{
    for (int i = 0; i < list.lenght; i++)
        if (list.data[i] == elem)
            return i;
    return -1;
}

void printList(SqList list)
{
    if (list.lenght <= 0)
    {
        printf("list 数据为空");
        return;
    }
    for (int i = 0; i < list.lenght; i++)
        printf("%d%c", list.data[i], i == getLen(list) - 1 ? '\n' : ' ');
    return;
}
int getLen(SqList list)
{
    return list.lenght;
}
int isEmpty(SqList list)
{
    return list.lenght <= 0;
}

void destoryList(SqList *list)
{
    free(list);
}