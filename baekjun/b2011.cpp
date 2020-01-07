#include <cstdio>
#include <cstring>

#define MOD 1000000

char pas[5005];
int dp[5005];

int calc (int idx)
{
    if (idx == (int)strlen(pas))
        return 1;

    int& ret = dp[idx];
    if (ret != -1)
        return ret = ret % MOD;
    ret = 0;
    if (pas[idx] == '0') {
        return 0;
    }
    else if (pas[idx] == '1') {
        ret += (calc(idx+1) % MOD + calc(idx+2) % MOD) % MOD;
    }
    else if (pas[idx] == '2') {
        ret += calc(idx+1) % MOD;
        if (pas[idx+1] <= '6') 
            ret += calc(idx+2) % MOD;
    }
    else {
        ret += calc(idx+1) % MOD;
    }
    return ret = ret % MOD;
}

int main (void)
{
    scanf("%s", pas);

    memset(dp, -1, sizeof(dp));
    int ans = calc(0) % MOD;
    printf("%d\n", ans);
}
