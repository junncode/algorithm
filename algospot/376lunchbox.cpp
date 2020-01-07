#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

#define MAXBOX 10000

int N, H[MAXBOX], allHot;
pair<int, int> E[MAXBOX];

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        scanf("%d", &N);
        allHot = 0;
        for (int hn = 0; hn < N; hn++) {
            scanf("%d", &H[hn]);
            allHot += H[hn];
        }
        for (int en = 0; en < N; en++) {
            int e;
            scanf("%d", &e);
            E[en] = make_pair(e, en);
        }
        sort(E, E+N);

        int curAll = allHot;
        int time = allHot + E[0].first;
        for (int i = 0; i < N-1; i++) {
            time = max(time, curAll - H[E[i].second] + E[i+1].first);
            curAll -= H[E[i].second];
        }
        printf("%d\n", time);
    }
    return 0;
}
