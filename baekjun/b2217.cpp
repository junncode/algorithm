#include <cstdio>
#include <algorithm>
using namespace std;

int main (void)
{
    int N, n[100005];
    scanf("%d", &N);
    for (int nn = 0; nn < N; nn++) 
        scanf("%d", &n[nn]);
    sort(n, n + N);
    int ans = 0;
    for (int nn = N-1; nn >= 0; nn--) 
        ans = max(ans, n[nn] * (N - nn));
    printf("%d\n", ans);
}
