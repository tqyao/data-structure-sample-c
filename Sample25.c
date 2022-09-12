#include <stdio.h>
#include <string.h>

int main()
{

    // char ch = '5';
    int num1 = 5, num2 = 5;
    num1 *= 2 + 1;        // num1 = num1 * (2+1);
    printf("%d\n", num1); // 15
    num2 *= 2;
    printf("%d\n", num2); // 10

    char ch1 = '5';
    // ch1 *= 2;
    // printf("%d\n", ch1);

    // int toNum1 = (int)ch1;
    int toNum1 = ch1 - '0';
    printf("%d\n", toNum1);
}
