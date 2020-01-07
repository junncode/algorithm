#include <cstdio>
#include <string>

int n, m, ans;
bool isFrd[10][10];

int makeFrd(bool isMatch[10])
{
    int firStd = -1;
    for (int i = 0; i < n; i++) {
        if (!isMatch[i]) {
            firStd = i;
            break;
        }
    }
    if (firStd == -1) {
        return 1;
    }

    int ret = 0;
    for (int i = firStd + 1; i < n; i++) {
        if (!isMatch[i] && isFrd[firStd][i]) {
            isMatch[firStd] = isMatch[i] = true;
            ret += makeFrd(isMatch);
            isMatch[firStd] = isMatch[i] = false;
        }
    }
    return ret;
}

int main(void)
{
    int C;
    scanf("%d", &C);
    bool isMatch[10];
    for (int tc = 0; tc < C; tc++) {
        scanf("%d %d", &n, &m);

        memset(isFrd, false, sizeof(isFrd));
        for (int mc = 0; mc < m; mc++) {
            int f1, f2;
            scanf("%d %d", &f1, &f2);
            isFrd[f1][f2] = isFrd[f2][f1] = true;
        }

        memset(isMatch, false, sizeof(isMatch));
        printf("%d\n", makeFrd(isMatch));
    }
    return 0;
}
