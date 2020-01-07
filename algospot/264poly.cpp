#include <cstdio>
#include <cstring>

#define MOD 10000000

int n, cashe[101][101];

int poly (int fir, int rem)
{
    if (fir == rem)
        return 1;

    int& ret = cashe[fir][rem];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 1; i <= rem - fir; i++) 
        ret = (ret + (poly(i, rem - fir) * (fir + i - 1) % MOD)) % MOD;
    return ret;
}

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        scanf("%d", &n);

        memset(cashe, -1, sizeof(cashe));
        int ans = 0;
        for (int i = 1; i <= n; i++) 
            ans = (ans + poly(i, n)) % MOD;
        printf("%d\n", ans);
    }
}
