#include <cstdio>
#include <algorithm>
using namespace std;

int main (void)
{
    int N, M, p[51], o[51], mod, ans = 0;
    scanf("%d %d", &N, &M);
    for (int mn = 0; mn < M; mn++) 
        scanf("%d %d", &p[mn], &o[mn]);
    sort(p, p + M);
    sort(o, o + M);
    if ((p[0] == 0) || (o[0] == 0)) {
        printf("0\n");
        return 0;
    }
    mod = p[0] / o[0];  // 3
    if (mod >= 6) {
        ans = N * o[0];
    }
    else if (mod >= 1) {
        ans = (N / 6) * p[0];
        int rem = N % 6;  // 4
        if (rem > mod) {
            ans += p[0];
        }
        else {
            ans += o[0] * rem;
        }
    }
    else {
        ans = (N / 6) * p[0];
        if ((N % 6) > 0)
            ans += p[0];
    }
    printf("%d\n", ans);
}
