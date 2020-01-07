#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, stair[305], dp[305];

void calc (void)
{
    for (int i = 2; i <= N; i++)
        dp[i] = max(stair[i-1] + dp[i-3], dp[i-2]) + stair[i];
}

int main (void)
{
    scanf("%d", &N);
    stair[0] = 0;
    for (int nn = 1; nn <= N; nn++) 
        scanf("%d", &stair[nn]);

    dp[1] = stair[1];
    calc();
    printf("%d\n", dp[N]);
}
