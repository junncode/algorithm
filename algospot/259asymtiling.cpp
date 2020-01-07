#include <cstdio>
#include <cstring>

#define MOD 1000000007

int n, cashe[101];

int count (int size)
{
    if (size <= 1) 
        return 1;

    int& ret = cashe[size];
    if (ret != -1)
        return ret;
    return ret = (count(size-1) + count(size -2)) % MOD;
}

int asym (int size)
{
    if (size % 2 == 1)
        return (count(size) - count(size/2) + MOD) % MOD;
    int ret = count(size);
    ret = (ret - count(size/2) + MOD) % MOD;
    ret = (ret - count(size/2-1) + MOD) % MOD;
    return ret;
}

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        scanf("%d", &n);

        memset(cashe, -1, sizeof(cashe));
        printf("%d\n", asym(n));
    }
    return 0;
}
