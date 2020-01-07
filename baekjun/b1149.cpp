#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, mon[1005][3], dp[1005][3];

int calc (int idx, int col)
{
    if (idx == N-1)
        return mon[idx][col];

    int& ret = dp[idx][col];
    if (ret != -1)
        return ret;
    return ret = mon[idx][col] + min(calc(idx+1, (col+1)%3), calc(idx+1, (col+2)%3));
}

int main (void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d %d %d", &mon[i][0], &mon[i][1], &mon[i][2]);

    memset(dp, -1, sizeof(dp));
    int ans = min(calc(0, 0), calc(0, 1));
    ans = min(ans, calc(0, 2));
    printf("%d\n", ans);
}
