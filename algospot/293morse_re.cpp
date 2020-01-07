#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define MAX 1000000000

int N, M, K;
int bino[201][201];

void calcBino (void)
{
    memset(bino, 0, sizeof(bino));
    for (int i = 0; i <= 200; i++) {
        bino[i][0] = bino[i][i] = 1;
        for (int j = 1; j < i; j++)
            bino[i][j] = min(MAX, bino[i-1][j-1] + bino[i-1][j]);
    }
}

string makeStr (int n, int m, int skip)
{
    if (n == 0)
        return string(m, 'o');
    if (skip < bino[n+m-1][n-1])
        return "-" + makeStr(n-1, m, skip);
    return "o" + makeStr(n, m-1, skip - bino[n+m-1][n-1]);
}

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        scanf("%d %d %d", &N, &M, &K);
        calcBino();
        cout << makeStr(N, M, K-1) << endl;
    }
}
