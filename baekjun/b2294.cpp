#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 987654321

int N, K, mon[105], dp[10005];

int calc (int sum)
{
    if (sum == K)
        return 0;
    if (sum > K)
        return INF;

    int& ret = dp[sum];
    if (ret != -1)
        return ret;
    ret = INF;
    for (int i = N-1; i >= 0; i--) 
        ret = min(ret, 1 + calc(sum + mon[i]));
    return ret;
}

int main (void)
{
    scanf("%d %d", &N, &K);
    for (int nn = 0; nn < N; nn++) 
        scanf("%d", &mon[nn]);
    sort(mon, mon + N);
    memset(dp, -1, sizeof(dp));
    int ans = calc(0);
    if (ans >= INF)
        printf("-1\n");
    else
        printf("%d\n", ans);
}
