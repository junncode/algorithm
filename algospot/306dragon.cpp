#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define MAX 1000000100

int N, P, L, cnt, d[51];
string ans;

void calc (void)
{
    for (int n = 0; n <= 50; n++) {
        if (n == 0)
            d[n] = 2;
        else 
            d[n] = min(MAX, d[n-1] * 2 + 1);
    }
}

string makeDrg (int n, int fb)
{
    if (n == 0) {
        if (fb == 0)
            return string("FX");
        else
            return string("YF");
    }

    if (n == 1) {
        if (fb == 0)
            return string("FX+YF");
        else
            return string("FX-YF");
    }

    return makeDrg(n-1, 0) + '+' + makeDrg(n-2, 0) + '-' + makeDrg(n-2, 1);
}

int main (void)
{
    int c;
    scanf("%d", &c);
    calc();
    for (int i = 0; i < 10; i++)
        printf("%d\n", d[i]);
    for (int tc = 0; tc < c; tc++) {
        scanf("%d %d %d", &N, &P, &L);
        cout << makeDrg(N, 0) << endl;
    }
}
