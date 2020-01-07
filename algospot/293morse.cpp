#include <cstdio>
#include <cstring>
using namespace std;

int n, m, k, all, cashe[205][205];
int cnt, ans[205];

void printAns (void)
{
    int idx = n-1;
    for (int i = 0; i < all; i++) {
        if ((idx >= 0) && (ans[idx] == i)) {
            printf("%c", 45);
            idx--;
        }
        else
            printf("%c", 111);
    }
    printf("\n");
}

int morse (int idx, int rem)
{
    printf("morse(%d, %d)\n", idx, rem);
    ans[rem] = idx;
    if (rem == 0) {
        //printf("  morse(%d, %d) 조건 return 1\n", idx, rem);
        cnt++;
        //printf(" ** cnt = %d\n", cnt);
        if (cnt == k) {
            printAns();
            memset(cashe, 0, sizeof(cashe));
        }
        return 1;
    }

    if (idx == -1) {
        int ret = 0;
        for (int i = 0; i < m+1; i++) 
            ret += morse(i, rem-1);
        return ret;
    }

    int& ret = cashe[idx][rem];
    if (ret != -1) {
        //printf("  morse(%d, %d) 다시 return %d\n", idx, rem, ret);
        return ret;
    }

    ret = 0;
    for (int next = idx+1; next <= all-rem; next++) {
        //printf("  morse(%d, %d) -> morse(%d, %d)\n", idx, rem, next, rem-1);
        ret += morse(next, rem-1);
    }
    //printf("  morse(%d, %d) 계산 return %d\n", idx, rem, ret);
    return ret;
}

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        scanf("%d %d %d", &n, &m, &k);
        all = n + m;
        cnt = 0;
        memset(cashe, -1, sizeof(cashe));
        morse(-1, n);
        printf("\n");
    }
}
