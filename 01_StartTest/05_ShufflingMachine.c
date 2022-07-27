#include <stdio.h>
#include <string.h>
#define SIZE 55
int main()
{
    // const int SIZE = 55;
    char cards[SIZE][4] =
        {"0", "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
         "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
         "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
         "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
         "J1", "J2"};

    int k;
    int orders[SIZE];
    if (scanf("%d", &k) != 1)
        return 0;

    for (int i = 1; i < SIZE; i++)
        if (scanf("%d", &orders[i]) != 1)
            return 0;

    // 最终卡牌位置
    int pos;
    // 最终卡牌位置对应卡
    char newCards[SIZE][4];
    for (int i = 1; i < SIZE; i++)
    {
        pos = orders[i];
        for (int j = 1; j < k; j++)
            pos = orders[pos];
        // newCards[pos] = &cards[i];
        strcpy(newCards[pos], cards[i]);
    }

    for (int i = 1; i < SIZE; i++)
        printf("%s%c", newCards[i], i == SIZE - 1 ? '\n' : ' ');

    return 0;
}
