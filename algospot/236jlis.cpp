#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int n, m, a[100], b[100], cashe[101][101];

int findJ (int idxA, int idxB)
{
    int& ret = cashe[idxA+1][idxB+1];
    if (ret != -1)
        return ret;

    ret = 0;
    long long A = (idxA == -1 ? NEGINF : a[idxA]);
    long long B = (idxB == -1 ? NEGINF : b[idxB]);
    long long curMax = max(A, B);
    for (int nA = idxA + 1; nA < n; nA++)
        if (curMax < a[nA])
            ret = max(ret, findJ(nA, idxB) + 1);
    for (int nB = idxB + 1; nB < m; nB++)
        if (curMax < b[nB])
            ret = max(ret, findJ(idxA, nB) + 1);
    return ret;
}

int main (void)
{
    int c;
    scanf("%d", &c);
    for (int tc = 0; tc < c; tc++) {
        scanf("%d %d", &n, &m);
        for (int nn = 0; nn < n; nn++)
            scanf("%d", &a[nn]);
        for (int mn = 0; mn < m; mn++)
            scanf("%d", &b[mn]);

        memset(cashe, -1, sizeof(cashe));
        printf("%d\n", findJ(-1, -1));
    }
    return 0;
}
