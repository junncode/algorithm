#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, stair[305], dp[305][2];

int calc (int n, int stack)
{
    if ((stack == 2) || n > N)
        return -987654321;
    if (n == N)
        return stair[N];

    if (n == 0) 
        return max(calc(n+1, stack+1), calc(n+2, 0));
    int& ret = dp[n][stack];
    if (ret != -1)
        return ret;
    return ret = stair[n] + max(calc(n+1, stack+1), calc(n+2, 0));
}

int main (void)
{
    scanf("%d", &N);
    stair[0] = 0;
    for (int nn = 1; nn <= N; nn++) 
        scanf("%d", &stair[nn]);

    memset(dp, -1, sizeof(dp));
    printf("%d\n", calc(0, -1));
}

