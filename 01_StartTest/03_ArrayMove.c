#include <stdio.h>
int main()
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