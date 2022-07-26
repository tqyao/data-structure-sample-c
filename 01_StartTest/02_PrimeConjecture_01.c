
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
int main01()
{
    int n;
    if (scanf("%d", &n) != 1)
    {
        return 0;
    }

    int cPrime, pPrime, count = 0;
    cPrime = pPrime = n;

    // printf("\n%d\n", isPrime(n));

    while (cPrime >= 5 && pPrime >= 3)
    {

        if (!isPrime(cPrime))
        {
            cPrime--;
            continue;
        }
        pPrime = cPrime - 2;
        if (!isPrime(pPrime))
        {
            cPrime = pPrime;
            continue;
        }
        count++;
        cPrime = pPrime;
    }
    printf("%d\n", count);

    return 0;
}

int isPrime(int num)
{
    // if (num == 3 || num == 5 || num == 7)
    //     return 1;
    // return num % 2 && num % 3 && num % 5;
    int i;
    if (num < 2)
        return 0;
    for (i = 2; i <= sqrt(num); i++)
        if (!(num % i))
            return 0;
    return 1;
}
