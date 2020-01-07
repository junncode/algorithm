#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int dr[3] = {0, 1, 1};
const int dc[3] = {1, 1, 0};
int R, C, A[1505][1505], B[1505][1505], dp[1505][1505];

int main (void)
{
    scanf("%d %d\n", &R, &C);
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    char s[9];
    for (int rn = 1; rn <= R; rn++)
        for (int cn = 1; cn <= C; cn++) {
            scanf("%s", s);
            (s[0] == 'A' ? A[rn][cn] : B[rn][cn]) += atoi(s+1);
        }
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++) {
            A[i][j] += A[i][j-1];
            B[i][C-j+1] += B[i][C-j+2];
        }
    printf("A->\n");
    for (int i = 0; i <= R; i++) {
        for (int j = 0; j <= C; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("B->\n");
    for (int i = 0; i <= R; i++) {
        for (int j = 0; j <= C; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (i == 1 || j == 1) {
                dp[i][j] = dp[i-1][j] + B[i][j+1];
                continue;
            }
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + A[i][j-1] + B[i][j+1];
            dp[i][j] = max(dp[i][j], dp[i][j-1] - B[i][j] + B[i][j+1]);
        }
    }
    printf("%d\n", dp[R][C]);
    for (int i = 0; i <= R; i++) {
        for (int j = 0; j <= C; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}
