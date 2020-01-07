#include <cstdio>
#include <cstring>

const int dm[4] = {-1, 0, 1, 0};
const int dn[4] = {0, 1, 0, -1};
int M, N, board[505][505], dp[505][505];

int calc (int curM, int curN)
{
    if ((curM == M-1) && (curN == N-1))
        return 1;

    int& ret = dp[curM][curN];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int dir = 0; dir < 4; dir++) {
        int nextM = curM + dm[dir];
        int nextN = curN + dn[dir];
        if ((nextM >= 0) && (nextM < M) && (nextN >= 0) && (nextN < N)) 
            if (board[nextM][nextN] < board[curM][curN]) 
                ret += calc(nextM, nextN);    
    }
    return ret;
}

int main (void)
{
    scanf("%d %d", &M, &N);
    for (int mn = 0; mn < M; mn++) 
        for (int nn = 0; nn < N; nn++)
            scanf("%d", &board[mn][nn]);

    memset(dp, -1, sizeof(dp));
    printf("%d\n", calc(0, 0));
}
