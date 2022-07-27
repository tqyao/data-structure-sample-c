#include <stdio.h>
#include <string.h>

int main()
{
    char str[25] = {0};
    if (scanf("%s", str) != 1)
        return 0;

    int dig[10] = {0}, check = 0;

    // 1. 计算输入 数字总数和数字种类
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        if (!dig[str[i] - '0'])
            check++;
        dig[str[i] - '0']++;
    }

    // 2. 数字翻倍
    int carry = 0, temp = 0;
    for (i--; i >= 0; i--)
    {
        temp = (str[i] - '0') * 2 + carry;
        str[i] = temp % 10 + '0';
        carry = temp / 10;
    }

    if (carry) // 3. 如果进位不为0，输出no和进位数字
        printf("No\n%d", carry);
    else
    {
        // 3. 如果进位为0，检查翻倍后数字与原数字个数，种类是否一只，一致输出yes
        for (int i = 0; i < strlen(str); i++)
        {
            dig[str[i] - '0']--;
            if (!dig[str[i] - '0'])
                check--;
        }
        if (check)
            printf("No\n");
        else
            printf("Yes\n");
    }

    // for (int i = 0; i < strlen(str); i++)
    printf("%s\n", str);

    return 0;
}

int main03(int argc, char **argv)
{
    char str[25] = {0};
    int dig[10] = {0};
    scanf("%s", str);
    int i, check = 0;
    for (i = 0; i < strlen(str); i++)
    {
        if (!dig[str[i] - '0'])
            check++;
        dig[str[i] - '0']++;
    }
    int num = 0;
    for (i--; i >= 0; i--)
    {
        int fk = num;
        num = (str[i] - '0') * 2;
        str[i] = (num + fk) % 10 + '0';
        num /= 10;
    }
    if (num)
        printf("No\n%d", num);
    else
    {
        for (i = 0; i < strlen(str); i++)
        {
            dig[str[i] - '0']--;
            if (!dig[str[i] - '0'])
                check--;
        }
        if (check)
            printf("No\n");
        else
            printf("Yes\n");
    }
    printf("%s\n", str);
    return 0;
}
int main02()
{
    // char str[21];
    char str[25];
    if (scanf("%s", str) != 1)
        return 0;

    int size = strlen(str);
    int nums[size];
    int dbSize = size > 20 ? 21 : size + 1;

    int dbNums[dbSize];

    for (int i = 0; i < size; i++)
        nums[i] = str[i] - '0';

    // 进位
    int carry = 0, temp = 0, count = 0;
    // x2 运算,结果保存到dbNums
    for (int i = size - 1; i >= -1; i--)
    {
        if (i == -1)
        {
            // dbNums[i+1] = carry;
            dbNums[0] = carry;
            break;
        }
        temp = nums[i] * 2;
        dbNums[i + 1] = temp % 10 + carry;
        carry = temp >= 10 ? temp / 10 : 0;
        if (count++ >= dbSize)
            break;
    }

    // 原数组去重，方便后续查找元素是否在其中
    int arr[10], arrlen = 0, flag = 0;
    for (int i = 0; i < size; i++)
    {
        temp = nums[i];

        for (int j = 0; j < arrlen; j++)
            if (arr[j] == temp)
            {
                flag = 1;
                break;
            }

        if (flag)
        {
            flag = 0;
            continue;
        }
        arr[arrlen++] = temp;
        if (arrlen >= 10)
            break;
    }

    // 查找dbNums中的元素是否都存在于nums去重后的arr中
    for (int i = 0; i < dbSize; i++)
    {
        if (i == 0 && !dbNums[0])
            continue;

        flag = 0;
        temp = dbNums[i];
        for (int j = 0; j < arrlen; j++)
            if (temp == arr[j])
            {
                // 在原始数组中找到相等元素
                flag = 1;
                break;
            }
        if (!flag)
            break;
    }

    if (flag)
        puts("Yes");
    else
        puts("No");

    for (int i = 0; i < dbSize; i++)
        if (i == 0 && !dbNums[0])
            continue;
        else
            printf("%d", dbNums[i]);

    return 0;
}
