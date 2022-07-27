#include <stdio.h>

int main(int argc, char **argv)
{
    int m, n;
    scanf("%d%d", &m, &n);
    int i, dig[105];
    for (i = 0; i < m; i++)
        scanf("%d", &dig[i]);
    // n 移动位数 n=2
    // m 一共几位数字 m = 6
    n = m - n;
    while (n < 0)
        n += m;
    for (i = 1; i <= m; i++)
    {
        n %= m;
        printf("%d%c", dig[n++], i == m ? '\n' : ' ');
    }
    return 0;
}
/**
 * 数组右移
 * @brief tqyao
 *
 * @return int
 */
int main02()
{
    int N, M;
    int arr[105];

    if (scanf("%d %d", &N, &M) != 2)
        return 0;

    int *p;
    for (p = arr; p < (arr + N); p++)
        if (scanf("%d", p) != 1)
            return 0;

    int initIdx = 0, idx = 0, toIdx, curContent = arr[0], toContent;
    int flag = 0;

    for (int i = 0; i < N; i++)
    {
        toIdx = (idx + M) % N;
        if (toIdx == initIdx)
            flag = 1;

        toContent = arr[toIdx];
        arr[toIdx] = curContent;
        curContent = toContent;
        idx = toIdx;

        if (flag)
        {
            initIdx = ++idx;
            curContent = arr[initIdx];
            flag = 0;
        }
    }

    for (p = arr; p < (arr + N - 1); p++)
        printf("%d ", *p);
    printf("%d\n", *p);
    return 0;
}