#include <cstdio>
#include <algorithm>
using namespace std;

int main (void)
{
    int N, time[1005], ans = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &time[i]);
    sort(time, time+N);
    for (int i = 1; i < N; i++) 
        time[i] += time[i-1];
    for (int i = 0; i < N; i++) 
        ans += time[i];
    printf("%d\n", ans);
}
