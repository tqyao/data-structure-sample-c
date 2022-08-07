/*
    查找算法中的“二分法”是这样定义的：

    给定N个从小到大排好序的整数序列List[]，以及某待查找整数X，我们的目标是找到X在List中的下标。即若有List[i]=X，则返回i；否则返回-1表示没有找到。

    二分法是先找到序列的中点List[M]，与X进行比较，若相等则返回中点下标；否则，若List[M]>X，则在左边的子系列中查找X；若List[M]<X，则在右边的子系列中查找X。

    试写出算法的伪码描述，并分析最坏、最好情况下的时间、空间复杂度。
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch(List L, ElementType X);

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch(L, X);
    printf("%d\n", P);

    return 0;
}

Position BinarySearch(List L, ElementType X)
{
    return 0;
}

List ReadInput()
{
}

/* 你的代码将被嵌在这里 */

int main01()
{
    const int size = 7;
    int list[size];

    printf("从小到大输入数组元素：\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &list[i]);

    int target = 1, idx = -1, temp;

    printf("输入您要查找的数字: ");
    scanf("%d", &target);
    int hight = size - 1, low = 0, mid = (low + hight) / 2;
    while (hight >= mid && low <= mid)
    {
        temp = list[mid];
        if (temp == target)
        {
            idx = mid;
            break;
        }
        if (target > temp)
            low = mid + 1;
        else
            hight = mid - 1;
        mid = (low + hight) / 2;
    }

    int len = sizeof(list) / sizeof(list[0]);
    for (int i = 0; i < len; i++)
        printf("%d ", *(list + i));

    printf("\n");
    if (idx == -1)
        printf("未找到\n");
    else
        printf("目标 %d 在数组中的索引为:%d\n", target, idx);

    return 0;
}