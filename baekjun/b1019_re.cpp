#include <cstdio>

// 51234
// fix = 51, level = 3  => 51000 ~ 51999
// fix = 2, level = 2  => 200 ~ 299
// fix = 3, level = 1  => 30 ~ 39
// fix = 34, level = 0  => 34 ~ 34

int cnt[10];

int pow10 (int a)
{
    int ret = 1;
    while (a--)
        ret *= 10;
    return ret;
}

void count (int fix, int level)
{
    if (fix == 0) {
        if (level == 0)
            return;
        for (int i = 0; i < 10; i++)
            cnt[i] += level * pow10(level - 1);
        for (int i = 1; i < level; i++)
            cnt[0] -= 9 * pow10(level - 1 - i) * i;
        cnt[0] -= level;
    }
    else {
        while (fix) {
            cnt[fix % 10] += pow10(level);
            fix /= 10;
        }   
        if (level == 0)
            return;
        for (int i = 0; i < 10; i++)
            cnt[i] += level * pow10(level - 1);
    }
}

int main (void)
{
    int N;
    scanf ("%d", &N);
    int now = 0;
    while (now < N+1) {
        for (int i = 0; ; i++) {
            if (now + pow10(i) > N+1) {
                count (now / pow10(i-1), i-1);
                now += pow10(i-1);
                break;
            }
        }
    }

    for (int i = 0; i< 10; i++)
        printf("%d ", cnt[i]);
    printf("\n");
}
