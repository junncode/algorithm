#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int n, d, p, t, q, numN[50];
bool board[50][50];
double ans[50];

void calc (int day, double du[])
{
    if (day > d) {
        for (int i = 0; i < n; i++)
            ans[i] = du[i];
        return;
    }
    
    double nextDu[50] = {0,};
    for (int isDu = 0; isDu < n; isDu++) 
        if (du[isDu] > 0) 
            for (int go = 0; go < n; go++) 
                if (board[isDu][go]) 
                    nextDu[go] += du[isDu] / numN[isDu];
    calc(day+1, nextDu);
}

int main (void)
{
    int c;
    scanf("%d", &c);
    for (int tc = 0; tc < c; tc++) {
        scanf("%d %d %d", &n, &d, &p);
        memset(board, false, sizeof(board));
        int tmp;
        for (int i = 0; i < n; i++) {
            int num = 0;
            for (int j = 0; j < n; j++) {
                scanf("%d", &tmp);
                if (tmp == 1) {
                    board[i][j] = true;
                    num++;
                }
            }
            numN[i] = num;
        }

        double du[50] = {0,};
        du[p] = 1;
        calc(1, du);

        scanf("%d", &t);
        for (int tn = 0; tn < t; tn++) {
            scanf("%d", &q);
            cout << fixed << setprecision(8) << ans[q] << ' ';
        }
        printf("\n");
    }
}
