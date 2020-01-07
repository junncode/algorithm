#include <cstdio>
#include <algorithm>
using namespace std;

int n, tri[100][100];

void up (int to) 
{
    if (to == -1)
        return;

    for (int i = 0; i <= to; i++) 
        tri[to][i] += max(tri[to+1][i], tri[to+1][i+1]);
    up(to-1);
    return;
}

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        scanf("%d", &n);
        for (int ts = 0; ts < n; ts++) 
            for (int tsn = 0; tsn < ts+1; tsn++) 
                scanf("%d", &tri[ts][tsn]);
        up(n-2);
        printf("%d\n", tri[0][0]);
    }
    return 0;
}
