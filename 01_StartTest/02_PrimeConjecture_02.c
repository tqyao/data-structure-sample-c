
#include <stdio.h>
#include <math.h>
// 素数猜想
// 让我们定义*d**n*为：*d**n*=*p**n*+1−*p**n*，其中*p**i*是第*i*个素数。显然有*d*1=1，且对于*n*>1有*d**n*是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

// 现给定任意正整数`N`(<105)，请计算不超过`N`的满足猜想的素数对的个数。
// 输入格式:
// 输入在一行给出正整数N。

// 输出格式:
// 在一行中输出不超过N的满足猜想的素数对的个数。

// 输入样例:
// 20
// 输出样例:
// 4
int isPrime(int num);

// int book[10005];
int book[100005];
// int main()
// {
//     printf("\n%d\n", isPrime(3));
//     return 0;
// }
int main()
{
    int n, res = 0;
    if (scanf("%d", &n) != 1)
    {
        return 0;
    }
    // printf("\n%d\n", isPrime(20));

    for (int i = 2; i <= n; i++)
        if (isPrime(i))
            book[i] = 1;
        else
            book[i] = 0;

    for (int i = 4; i <= n; i++)
        if (book[i] && book[i] - book[i - 2] == 0)
            res++;

    printf("%d\n", res);

    return 0;
}

int isPrime(int num)
{
    if (num < 2)
        return 0;
    int k = (int)(sqrt(num));
    for (int i = 2; i <= k; i++)
        if (!(num % i)) //能整出就返回0
            return 0;
    return 1;
}