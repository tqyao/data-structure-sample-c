#include <stdio.h>
#include <string.h>
/**
 * @brief
 * 探究是否能在函数中获取实参字符串长度
 * 结论:可以
 * @param strs
 */
void test(char strs[])
{
    printf("test => %lu\n", strlen(strs));
}
int main()
{
    test("abcde");
    return 1;
}
