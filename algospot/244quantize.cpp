#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF 987654321

int N, S, n[100], cashe[100][10], minCashe[100][100];

int minErr (int idx, int size)
{
    int& ret = minCashe[idx][size];
    if (ret != -1)
        return ret;

    if (size == 1)
        return ret = 0;

    int m, sum = 0;
    float tmp;
    for (int i = idx; i < idx+size; i++)
        sum += n[i];
    tmp = (float)sum / (float)size;
    m = tmp;
    if (tmp - m >= 0.5)
        m++;
    ret = 0;
    for (int i = idx; i < idx+size; i++) 
        ret += (n[i] - m) * (n[i] - m);
    return ret;
}

int divide (int idx, int remGrp)
{
    if (idx == N) 
        return 0;
    if (remGrp == 0)
        return INF;

    int& ret = cashe[idx][remGrp];
    if (ret != -1)
        return ret;

    ret = INF;
    for (int i = 1; idx + i <= N; i++) 
        ret = min(ret, minErr(idx, i) + divide(idx+i, remGrp-1));
    return ret;
}

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        scanf("%d %d", &N, &S);
        for (int nn = 0; nn < N; nn++) {

            scanf("%d", &n[nn]);
        }
        sort(n, n+N);
        memset(cashe, -1, sizeof(cashe));
        memset(minCashe, -1, sizeof(minCashe));
        printf("%d\n", divide(0, S));
    }
}
