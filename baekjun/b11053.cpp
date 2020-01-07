#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, A[1005], dp[1005];

int calc (int idx)
{
    int& ret = dp[idx+1];
    if (ret != -1)
        return ret;
    ret = 1;
    for (int next = idx+1; next < N; next++)
        if (idx == -1 || A[idx] < A[next])
            ret = max(ret, calc(next) + 1);
    return ret;
}

int main (void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", calc(-1)-1);
}
