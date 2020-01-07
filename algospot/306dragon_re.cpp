#include <cstdio>
#include <iostream>
#include <cassert>
#include <cstring>
#include <string>
using namespace std;

#define MAX 1000000100

int N, P, L, cnt, d[51];
char ans[55];

void calc (void)
{
    for (int n = 0; n <= 50; n++) {
        if (n == 0)
            d[n] = 1;
        else 
            d[n] = min(MAX, d[n-1] * 2 + 2);
    }
}

char expand (const string& dragonCurve, int generations, int skip)
{
    /*
    printf("expand(");
    cout << dragonCurve;
    printf(", %d, %d)\n", generations, skip);*/
    if (generations == 0) 
        return dragonCurve[skip];

    for (int i = 0; i < dragonCurve.size(); i++) {
        if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
            if (skip >= d[generations])
                skip -= d[generations];
            else if (dragonCurve[i] == 'X')
                return expand("X+YF", generations-1, skip);
            else
                return expand("FX-Y", generations-1, skip);
        }
        else if (skip > 0)
            --skip;
        else
            return dragonCurve[i];
    }
    return '$';
}

int main (void)
{
    int c;
    scanf("%d", &c);
    calc();
    for (int tc = 0; tc < c; tc++) {
        scanf("%d %d %d", &N, &P, &L);
        for (int i = P; i < P+L; i++) {
            printf("%c", expand("FX", N, i-1));
        }
        printf("\n");
    }
}
