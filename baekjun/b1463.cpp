#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int cashe[1000005];

int calc (int n)
{
    if (n == 1)
        return 0;

    int& ret = cashe[n];
    if (ret != -1)
        return ret;

    ret = 987654321;
    if ((n % 3) == 0) 
        ret = min(ret, 1 + calc(n/3));  
    if ((n % 2) == 0)
        ret = min(ret, 1 + calc(n/2));
    ret = min(ret, 1 + calc(n-1));
    return ret;
}

int main (void)
{
    int N;
    scanf("%d", &N);

    memset(cashe, -1, sizeof(cashe));
    cashe[2] = 1;
    cashe[3] = 1;
    printf("%d\n", calc(N));
}
