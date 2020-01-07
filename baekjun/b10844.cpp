#include <cstdio>
#include <cstring>

#define MOD 1000000000

int N, dp[10][101];

int calc (int pre, int rem)
{
    if (rem == 0)
        return 1;

    int& ret = dp[pre][rem];
    if (ret != -1)
        return ret;
    if (pre == 0)
        return ret = (calc(1, rem-1)) % MOD;
    else if (pre == 9)
        return ret = (calc(8, rem-1)) % MOD;
    else
        return ret = ((calc(pre-1, rem-1)) % MOD + (calc(pre+1, rem-1)) % MOD) % MOD;
}

int main (void)
{
    scanf("%d", &N);

    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 1; i <= 9; i++) 
        ans = (ans + calc(i, N-1) % MOD) % MOD;
    printf("%d\n", ans);
}
