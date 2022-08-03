#include <stdio.h>
#include <math.h>
#include <time.h>
#define MAXN 101
#define COUNT 1e7
void calRunTime(char[], double (*)(int, double[], double));
double fx1(int, double[], double);
double fx2(int, double a[], double x);
int main()
{
    calRunTime("fx1", fx1);
    calRunTime("fx2", fx2);
}
void calRunTime(char funcName[], double (*func)(int n, double a[], double x))
{
    clock_t start, end;
    double duration;
    double a[MAXN];
    int i = 1;
    a[i] = 1;
    for (i = 1; i < MAXN; i++)
        a[i] = (double)(1 / i);

    start = clock();
    for (int i = 0; i < COUNT; i++)
        func(MAXN - 1, a, 1.1);
    end = clock();

    duration = (double)(end - start);
    printf("%s打点总次数为:%lf\n", funcName, duration);
    printf("%s平均每次执行时间:%6.2e\n", funcName, duration / CLOCKS_PER_SEC / COUNT);
    return;
}

double fx1(int n, double a[], double x)
{
    double res = a[0];
    for (int i = 1; i <= n; i++)
        res += a[i] * pow(x, i);
    return res;
}
double fx2(int n, double a[], double x)
{
    double res = a[n];
    for (int i = n; i > 0; i--)
        res = a[i - 1] + x * res;
    return res;
}
