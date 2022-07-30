#include <stdio.h>
#include <math.h>
#include <time.h>
// f(x) = a0 + a1x + a2x2 +…+ anxn
double fx1(int n, double a[], double x);

//   f(x) = a0 + x (a1+ x (a2 +… + x (an) …)
double fx2(int n, double a[], double x);

double calRunTime(char funcName[], double (*func)(int n, double a[], double x));

// 多项式最大项数 = 多项式阶数+1，此处我们计算的是九阶多项式
#define MAXN 10
int main()
{
    calRunTime("fx1", fx1);
    calRunTime("fx2", fx2);
    return 0;
}

double fx1(int n, double a[], double x)
{
    double res = a[0];
    for (int i = 1; i <= n; i++)
        res += a[i] * pow(x, i);
    return res;
}

//   f(x) = a0 + x (a1+ x (a2 +… + x (an) …)
double fx2(int n, double a[], double x)
{
    double res = a[n];
    for (int i = n; i > 0; i--)
        res = a[i - 1] + x * res;
    return res;
}

double calRunTime(char funcName[], double (*func)(int n, double a[], double x))
{
    clock_t start, end;
    // double duration;

    double a[MAXN];
    for (int i = 0; i < MAXN; i++)
        a[i] = (double)i;

    int count = 1e7;
    start = clock();
    for (int i = 0; i < count; i++)
        func(MAXN - 1, a, 1.1);
    end = clock();

    printf("%s平均打点数%lf\n", funcName, (double)(end - start));
    printf("%s运行时间：%6.2e\n", funcName, ((double)(end - start) / CLOCKS_PER_SEC / count));
}