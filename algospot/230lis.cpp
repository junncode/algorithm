#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int N, s[500], cashe[500];

int find (int idx)
{
    int& ret = cashe[idx];
    if (ret != -1)
        return ret;

    ret = 1;
    for (int i = idx+1; i < N; i++) 
        if (s[idx] < s[i])
            ret = max(ret, find(i) + 1);
    return ret;
}

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        scanf("%d", &N);
        for (int sn = 0; sn < N; sn++) 
            scanf("%d", &s[sn]);

        memset(cashe, -1, sizeof(cashe));
        for (int i = 0; i < N; i++)
            find(i);

        sort(cashe, cashe + N);
        printf("%d\n", cashe[N-1]);
    }
    return 0;
}
