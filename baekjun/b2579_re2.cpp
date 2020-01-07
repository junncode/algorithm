#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, stair[305], dp[305];

int calc (int n)
{

}

int main (void)
{
    scanf("%d", &N);
    stair[0] = 0;
    for (int nn = 1; nn <= N; nn++) 
        scanf("%d", &stair[nn]);

    memset(dp, -1, sizeof(dp));
    printf("%d\n", calc(N));
}

