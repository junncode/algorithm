#include <cstdio>


int main (void)
{
    int m, ans = 0;
    scanf("%d", &m);
    m = 1000 - m;
    ans += (m / 500); m %= 500;
    ans += (m / 100); m %= 100;
    ans += (m / 50); m %= 50;
    ans += (m / 10); m %= 10;
    ans += (m / 5); m %= 5;
    ans += (m / 1); m %= 1;
    printf("%d\n", ans);
    return 0;
}
