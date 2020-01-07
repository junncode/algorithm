#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXSIZE 200000

int N;
int fence[MAXSIZE];
int ans = -1;

int goL (int cur)
{
    int cnt = 0;
    for (int i = cur; i >= 0; i--) {
        if (fence[i] >= fence[cur]) {
            ++cnt;
        }
        else
            break;
    }
    return cnt;
}

int goR (int cur)
{
    int cnt = 0;
    for (int i = cur; i < N; i++) {
        if (fence[i] >= fence[cur]) {
            ++cnt;
        }
        else
            break;
    }
    return cnt;
}

void findMax (void)
{
    for (int i = 0; i < N; i++) {
        int rec;
        rec = (goL(i) + goR(i) - 1) * fence[i];
        ans = max(ans, rec);
    }
}

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        scanf("%d", &N);

        for (int fenNum = 0; fenNum < N; fenNum++) 
            scanf("%d", &fence[fenNum]);

        ans = -1;
        findMax();
        printf("%d\n", ans);
    }
    return 0;
}
