#include <cstdio>
#include <cstring>

int N;
long long dp[2][91];

long long calc (int pre, int rem)
{
    if (rem == 0)
        return 1;

    long long& ret = dp[pre][rem];
    if (ret != -1)
        return ret;
    if (pre == 0)
        return ret = calc(0, rem-1) + calc(1, rem-1);
    else
        return ret = calc(0, rem-1);
}

int main (void)
{
    scanf("%d", &N);
    
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", calc(1, N-1));
}
