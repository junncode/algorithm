#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, m, foodM[20], foodL[20], cashe[201];

int calc ()
{
    int ret = 0;
    cashe[0] = 0;
    for (int mon = 1; mon <= m; mon++) {
        int cand = 0;
        for (int i = 0; i < N; i++) {
            if (mon >= foodM[i])
                cand = max(cand, cashe[(mon - foodM[i])%201] + foodL[i]);
        }
        cashe[mon % 201] = cand;
        ret = max(ret, cand);
    }
    return ret;
}

int main (void)
{
    int c;
    scanf("%d", &c);
    for (int tc = 0; tc < c; tc++) {
        scanf("%d %d", &N, &m);
        m /= 100;
        for (int n = 0; n < N; n++) {
            scanf("%d %d", &foodM[n], &foodL[n]);
            foodM[n] /= 100;
        }

        memset(cashe, -1, sizeof(cashe));
        printf("%d\n", calc());
    }
}
