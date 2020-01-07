#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, wine[10005], dp[10005][2];

int calc (int idx, int stack)
{
    if (stack == 2)
        return -987654321;
    if (idx == N)
        return wine[N];
    if (idx > N)
        return 0;

    if (idx == 0)
        return max(calc(idx+1, 0), calc(idx+2, 0));
    int& ret = dp[idx][stack];
    if (ret != -1)
        return ret;
    return ret = max(calc(idx+1, 0), wine[idx] + max(calc(idx+1, stack+1), calc(idx+2, 0)));
}

int main (void)
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) 
        scanf("%d", &wine[i]);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", calc(0, -1));
}
