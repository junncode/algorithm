#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define NEVER -987654321

int n, num[50], cashe[50][50];

void makeClear (void)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cashe[i][j] = NEVER;
}

int play (int left, int right)
{
    if (left > right)
        return 0;

    int& ret = cashe[left][right];
    if (ret != NEVER)
        return ret;
    
    ret = max(num[left] - play(left+1, right), num[right] - play(left, right -1));
    if (right - left + 1 >= 2) {
        ret = max(ret, -play(left+2, right));
        ret = max(ret, -play(left, right-2));
    }
    return ret;
}

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        scanf("%d", &n);
        for (int N = 0; N < n; N++)
            scanf("%d", &num[N]);

        makeClear();
        printf("%d\n", play(0, n-1));
    }
}
