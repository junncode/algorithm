#include <cstdio>
#include <algorithm>
using namespace std;

int n, num[100005], dp[100005];

int main (void)
{
    scanf("%d", &n);
    for (int nn = 0; nn < n; nn++) 
        scanf("%d", &num[nn]);

    dp[0] = num[0];
    for (int i = 1; i < n; i++)
        dp[i] = max(dp[i-1] + num[i], num[i]);

    int ans = dp[0];
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    printf("%d\n", ans);
}
