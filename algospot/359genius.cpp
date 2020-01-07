#include <cstdio>

int N, K, M, n[50];
float t[50][50];

float calc (int k, float curT[50])
{
    if (k == K)
        return curT[0];

    float ret = 0.0;
    float nextT[50] = {0.0, };
    for (int songNum = 0; songNum < N; songNum++) {
        if (curT[songNum] > 0) {  // songNum번의 노래가 확률이 있다면
            for (int i = 0; i < N; i++) {  // i번의 노래로 갈 확률
                nextT[i] = curT[songNum] * t[songNum][i];
                ret += calc(k + n[])
            }
        }
    }
}

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        scanf("%d %d %d\n", &N, &K, &M);
        for (int sn = 0; sn < N; sn++) 
            scanf("%d", &n[sn]);
        for (int tb = 0; tb < N; tb++) 
            for (int ta = 0; ta < N; ta++) 
                scanf("%f", &t[tb][ta]);
        for (int mn = 0; mn < M; m++) {
            int fsn;
            scanf ("%d", &fsn);
            float curT[50] = {0.0, };
            curT[fsn] = 1;
            cout << fixed << setprecision(8) << calc(0, curT) << ' ';
        }
        printf("\n");
    }
}
