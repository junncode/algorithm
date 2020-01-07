#include <cstdio>
#include <cstring>

int N, dp[1005];

int calc (int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    int& ret = dp[n];
    if (ret != -1)
        return ret;
    return ret = ((calc(n-1) % 10007) + (calc(n-2) % 10007)) % 10007;
}

int main (void)
{
    scanf("%d", &N);

    memset(dp, -1, sizeof(dp));
    printf("%d\n", calc(N));
}
