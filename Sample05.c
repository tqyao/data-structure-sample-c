#include <stdio.h>
#include <string.h>

//通过debug监视变量查看初始值
int nums3[10];
char chs3[10];
int main()
{
    // 字符串赋值问题

    // - 指针指向字符地址（指针=地址）
    char *ch1 = "我爱你";
    char ch2[10];
    strcpy(ch2, ch1);

    printf("%s\n", ch1);
    printf("%s\n", ch2);
    printf("%d\n", strlen(ch1));

    // 数组初始化问题
    printf("\n");
    int nums2[10];
    int nums[10] = {0};
    char chs2[10];
    char chs[10] = {'0'};

    printf("%s\n", chs3);
}