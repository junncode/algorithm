#include <cstdio>
#include <algorithm>
using namespace std;

int main (void)
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    printf("%d\n", min(N/2, min(M, (N + M - K) / 3)));
    return 0;
}
