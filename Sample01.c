#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
void PrintHourGlass(int a, char *b);
int main()
{
    // int a, b;

    // while (scanf("%d %d", &a, &b) != EOF)

    int n;
    char str[10];
    // scanf("%d %s", &n, str);
    // printf("%d %s", n, str);

    if (scanf("%d %s", &n, str) == 2)
    {
        PrintHourGlass(n, str);
    }

    // PrintHourGlass(n, str);
    return 0;
}

void PrintHourGlass(int n, char *ch)
{

    double row = 0;
    int leave = 0;
    char res[100000] = "";
    char toNum[10];

    if (n <= 6)
    {
        sprintf(toNum, "%d", n);

        strcat(res, "\n");
        strcat(res, toNum);
        printf("%s", res);
        return;
    }
    while (1)
    {
        if (n % 2 == 0) // 所给星星数量不得为偶数
        {
            n--;
            leave++;
            continue;
        }

        // 根据等差数列 前n 项和公式求出行数
        row = sqrt(n / 2 + 1);
        if (row != (int)row) // 判断是否为整数
        {
            n--;
            leave++;
            continue;
        }
        break;
    }

    // printf("=========\n");
    // printf("row = %lf\n", row);
    // printf("leave = %d\n", leave);
    // printf("=========\n");

    // 总行数
    int sumRow = row;
    // 总列数
    int sumCol = row + row - 1;
    // 当前列需要打印多少星星
    int currentStar = sumCol;
    // 当前列需要打印多少空格
    int currentSpace = 0;

    for (int i = 0; i < sumRow; i++)
    {
        currentStar = sumCol - i * 2;
        currentSpace = (sumCol - currentStar) / 2;
        // for (int j = 0; j < sumCol; j++)
        // j >= currentSpace &&j < sumCol - currentSpace ? strcat(res, ch) : strcat(res, " ");
        // strcat(res, "\n");
        for (int j = 0; j < sumCol; j++)
        {
            if (j >= currentSpace && j < sumCol - currentSpace)
                strcat(res, ch);
            else
                strcat(res, " ");
        }
        strcat(res, "\n");
    }

    currentStar = sumCol;
    currentSpace = 0;
    for (int i = 1; i <= sumRow; i++)
    {
        if (i == 1)
            continue;

        currentStar = 2 * i - 1;
        currentSpace = (sumCol - currentStar) / 2;
        // for (int j = 0; j < sumCol; j++)
        // j >= currentSpace &&j < sumCol - currentSpace ? strcat(res, ch) : strcat(res, " ");

        for (int j = 0; j < sumCol; j++)
        {
            if (j >= currentSpace && j < sumCol - currentSpace)
            {
                strcat(res, ch);
            }
            else
            {
                strcat(res, " ");
            }
        }
        strcat(res, "\n");
    }
    // strcat(res, "\n");

    sprintf(toNum, "%d", leave);
    strcat(res, toNum);
    printf("%s", res);
}