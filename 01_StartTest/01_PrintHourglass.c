#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // 用户给与符号数
    int sumCh;
    char ch;

    if (scanf("%d %c", &sumCh, &ch) != 2)
        return 0;
    // 列， 该列所需符号数， 剩余符号数
    int col = 1, fullCount = 1, leaveCount = sumCh - fullCount;
    // (col + 2) * 2 是计算相邻沙漏图形相差的符号数
    while (leaveCount >= (col + 2) * 2)
    {
        col += 2;
        fullCount += col * 2;
        leaveCount = sumCh - fullCount;
    }

    // printf("\n%d\n", col);
    // printf("leave:%d\n", leaveCount);

    // 当前行的列所需符号数
    int colOfCrrRow = col;
    while (colOfCrrRow >= 1)
    {
        int leaveColOfCrrRow = colOfCrrRow, spaceCount = (col - leaveColOfCrrRow) / 2;
        while (spaceCount--)
            putchar(' ');

        while (leaveColOfCrrRow--)
            putchar(ch);

        colOfCrrRow -= 2;
        putchar('\n');
    }

    int n = 3;
    while (n <= col)
    {
        int chCount = n, spaceCount = (col - n) / 2;
        while (spaceCount--)
            putchar(' ');

        while (chCount--)
            putchar(ch);

        n += 2;
        putchar('\n');
    }

    printf("%d\n", leaveCount);

    return 0;
}

// https://www.cxybb.com/article/belous_zxy/81456347
int main03(int argc, char **argv)
{

    int sum;
    char ch;
    scanf("%d %c", &sum, &ch);
    int i = 1, msum = 1, fk = sum - msum;
    while (fk >= (i + 2) * 2)
    {
        i += 2;
        msum += 2 * i;
        fk = sum - msum;
    }

    // i:总列数，ins:当前行符号数
    int ins = i;
    while (ins > 1) // 打印到该行符号数为1之前
    {
        // ind：当前符号剩余数  inf:空格数
        int ind = ins, inf = (i - ins) / 2;
        while (inf--)
            putchar(' ');
        while (ind--)
            putchar(ch);
        putchar('\n');
        ins -= 2;
    }

    // 轴对称中心的一个符号行
    int inf = (i - 1) / 2;
    while (inf--)
        putchar(' ');
    putchar(ch);
    putchar('\n');

    ins = 3;
    while (ins <= i)
    {
        // ind：当前打印符号剩余数 inf：当前行打印空格数
        int ind = ins, inf = (i - ins) / 2;
        while (inf--)
            putchar(' ');
        while (ind--)
            putchar(ch);
        putchar('\n');
        ins += 2;
    }
    printf("%d\n", fk);
    return 0;
}

// 打印沙漏
void PrintHourGlass(int a, char *b);
int main02()
{

    printf("\n");
    // char str[500] = "";

    // char ch[] = "*";
    // strcat(str, ch);
    // printf("%s\n", str);
    PrintHourGlass(32, "*");

    // for (double i = 0; i < 4; i++)
    // {
    //     printf("hello : %lf\n", i);
    // }

    // double a = 3;
    // printf("%d", a == (int)a);
    return 0;
}

void PrintHourGlass(int n, char *ch)
{

    double row = 0;
    int leave = 0;
    while (1)
    {
        if (n % 2 == 0) // 所给星星数量不得为偶数
        {
            n--;
            leave++;
            continue;

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

        printf("=========\n");
        printf("row = %lf\n", row);
        printf("leave = %d\n", leave);
        printf("=========\n");

        // 总行数
        int sumRow = row;
        // 总列数
        int sumCol = row + row - 1;
        // 当前列需要打印多少星星
        int currentStar = sumCol;
        // 当前列需要打印多少空格
        int currentSpace = 0;

        char res[500] = "";
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

        char toNum[10];
        sprintf(toNum, "%d", leave);
        strcat(res, toNum);
        printf("%s", res);
    }
}