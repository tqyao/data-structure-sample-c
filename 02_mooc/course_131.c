#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 01-复杂度2 Maximum Subsequence Sum
//  思路二：
int main()
{
    int size;
    if (scanf("%d", &size) != 1)
        return 0;

    int *arr = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
        if (scanf("%d", &arr[i]) != 1)
            return 0;

    int head, tail;
    int curSum, maxSum;
    int gen = 0;
    int flag = 0;
    head = tail = -1;
    curSum = maxSum = 0;

    for (int i = 0; i < size; i++)
    {
        curSum += arr[i];
        if (curSum >= 0)
        {
            gen++;
        }
        else if (curSum < 0)
        {
            gen = 0;
            curSum = 0;
        }

        if (curSum > maxSum)
        {
            flag = 1;
            maxSum = curSum;
            tail = i;
            head = i - gen + 1;
        }

        if (!flag && !maxSum && !arr[i])
        {
            flag = 1;
            head = tail = i;
        }
    }

    if (head == -1)
    {
        head = 0;
        tail = size - 1;
        maxSum = 0;
    }

    printf("%d %d %d\n", maxSum, arr[head], arr[tail]);

    return 0;
}

// 01-复杂度2 Maximum Subsequence Sum
// 思路一：
int main02()
{
    int size;
    if (scanf("%d", &size) != 1)
        return 0;

    // for (int i = 0; i < size; i++)
    //     if (scanf("%d", &arr[i]) != 1)
    //         return 0;

    int *arr = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
        if (scanf("%d", &arr[i]) != 1)
            return 0;

    int tail = -1, head = -1, flag = 0;
    int curSum, maxSum;
    int tempHead = 0;
    curSum = 0;
    maxSum = 0;
    for (int i = 0; i < size; i++)
    {
        curSum += arr[i];

        if (curSum < 0)
        {
            curSum = 0;
            tempHead = -1;
        }
        else if (curSum >= 0 && tempHead == -1)
            tempHead = i;

        if (curSum > maxSum)
        {
            flag = 2;
            maxSum = curSum;
            head = tempHead;
            tail = i;
        }

        if (!maxSum && !flag && !arr[i])
        {
            flag = 1;
            head = tail = i;
        }
    }

    if (head == -1)
    {
        head = 0;
        tail = size - 1;
        maxSum = 0;
    }

    printf("%d %d %d\n", maxSum, arr[head], arr[tail]);

    return 0;
}

/**
 * 最大子列和问题：给定一个序列，求所有连续子列中最大值
 * @brief
 *
 * @return int
 */

int maxSubseqSum1(int A[], int N);

int maxSubseqSum2(int A[], int N);

// 分治算法
int maxSubseqSum3(int A[], int N);
int DivideAndConquer(int A[], int left, int right);
int max3(int num1, int num2, int num3);
// 在线处理 O(n)
int maxSubseqSum4(int A[], int N);

int main01()
{
    int size, arr[100000];
    clock_t start1, end1, start2, end2, start3, end3, start4, end4;
    printf("请输入输入序列长度>> ");
    if (scanf("%d", &size) != 1)
        return 0;

    // // printf("请输入序列元素>> ");
    // for (int i = 0; i < size; i++)
    //     if (scanf("%d", &arr[i]) != 1)
    //         return 0;

    srand((unsigned)time(NULL));
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 201 - 100;

    // printf("连续子序列最大值：%d\n", maxSubseqSum1(arr, size));
    // printf("连续子序列最大值：%d\n", maxSubseqSum2(arr, size));
    // printf("连续子序列最大值：%d\n", maxSubseqSum3(arr, size));

    start1 = clock();
    printf("%d\n", maxSubseqSum1(arr, size));
    end1 = clock();
    start2 = clock();
    printf("%d\n", maxSubseqSum2(arr, size));
    end2 = clock();
    start3 = clock();
    printf("%d\n", maxSubseqSum3(arr, size));
    end3 = clock();
    start4 = clock();
    printf("%d\n", maxSubseqSum4(arr, size));
    end4 = clock();
    printf("sum1 运行时间:%lf\n", (double)(end1 - start1) / CLOCKS_PER_SEC);
    printf("sum2 运行时间:%lf\n", (double)(end2 - start2) / CLOCKS_PER_SEC);
    printf("sum3 运行时间:%lf\n", (double)(end3 - start3) / CLOCKS_PER_SEC);
    printf("sum4 运行时间:%lf\n", (double)(end4 - start4) / CLOCKS_PER_SEC);

    // printf("%d\n", maxSubseqSum2(arr, size));
    // printf("%d\n", maxSubseqSum3(arr, size));
    return 0;
}

int maxSubseqSum1(int A[], int N)
{
    int maxSum = 0, curSum;
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
        {
            curSum = 0;
            for (int k = i; k <= j; k++)
                curSum += A[k];
            if (curSum > maxSum)
                maxSum = curSum;
        }
    return maxSum;
}

int maxSubseqSum2(int A[], int N)
{
    int maxSum = 0, curSum;
    for (int i = 0; i < N; i++)
    {
        curSum = 0;
        for (int j = i; j < N; j++)
        {
            curSum += A[j];
            if (curSum > maxSum)
                maxSum = curSum;
        }
    }
    return maxSum;
}
int maxSubseqSum4(int A[], int N)
{
    int maxSum, curSum;
    maxSum = curSum = 0;
    for (int i = 0; i < N; i++)
    {
        curSum += A[i];
        if (curSum > maxSum)
            maxSum = curSum;
        else if (curSum < 0)
            curSum = 0;
    }
    return maxSum;
}

int maxSubseqSum3(int A[], int N)
{
    return DivideAndConquer(A, 0, N - 1);
}

int DivideAndConquer(int A[], int left, int right)
{

    // 递归终止条件
    if (left == right)
    {
        if (A[left] > 0)
            return A[left];
        else
            return 0;
    }

    // 先分
    int center, leftDivideResult, rightDivideResult;
    center = (left + right) / 2;
    // 分别保存 左、右子列最大子列和递归结果
    leftDivideResult = DivideAndConquer(A, left, center);
    rightDivideResult = DivideAndConquer(A, center + 1, right);

    // 再治
    // 计算跨越左、右边界最大子列和
    int maxLeftSum = 0, maxRightSum = 0;
    int curLeftSum = 0, curRightSUm = 0;

    for (int i = center; i >= left; i--)
    {
        curLeftSum += A[i];
        if (curLeftSum > maxLeftSum)
            maxLeftSum = curLeftSum;
    }

    for (int i = center + 1; i <= right; i++)
    {
        curRightSUm += A[i];
        if (curRightSUm > maxRightSum)
            maxRightSum = curRightSUm;
    }

    return max3(leftDivideResult, rightDivideResult, maxLeftSum + maxRightSum);
}

int max3(int num1, int num2, int num3)
{
    return num1 > num2 ? (num1 > num3 ? num1 : num3) : (num2 > num3 ? num2 : num3);
}