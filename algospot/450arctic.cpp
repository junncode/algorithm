#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
double loc[100][2], howFar[100][100];

void calcFar (void)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double cal = pow(loc[i][0] - loc[j][0], 2) + pow(loc[i][1] - loc[j][1], 2);
            cal = sqrt(cal);
            howFar[i][j] = howFar[j][i] = cal;
        }
    }
}

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        scanf("%d", &N);
        for (int nn = 0; nn < N; nn++) 
            scanf("%lf %lf", &loc[nn][0], &loc[nn][1]);
        
        calcFar();
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < N; j++)
                printf("%d -> %d : %lf\n", i, j, howFar[i][j]);
        printf("%lf\n", sqrt(pow(1000,2)*2));
    }
}
