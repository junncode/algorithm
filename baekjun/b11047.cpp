#include <cstdio>

int N, K, A[10];

int main (void)
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) 
        scanf("%d", &A[i]);
    int ans = 0;
    while (N-- && K) {
        if (A[N] > K)
            continue;
        ans += K / A[N];
        K = K % A[N];
    }
    printf("%d\n", ans);
}
