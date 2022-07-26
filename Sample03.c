#include <stdio.h>
#include <math.h>
int book[100005];
int isprime(int m)
{
    int i;
    if (m < 2)
        return 0;
    for (i = 2; i <= sqrt(m); i++)
        if (!(m % i))
            return 0;
    return 1;
}

int main()
{
    int n = isprime(25);
    printf("\n%d\n", n);
    return 0;
}