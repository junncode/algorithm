#include <cstdio>
#include <utility>
using namespace std;

pair<int, int> dp[40];

pair<int, int> fibo (int n)
{
    if (n == 0) 
        return make_pair(1, 0);
    else if (n == 1) 
        return make_pair(0, 1);

    pair<int, int>& ret = dp[n];
    if (ret != make_pair(-1, -1))
        return ret;

    return ret = make_pair(fibo(n-1).first + fibo(n-2).first, fibo(n-1).second + fibo(n-2).second);
}

int main (void)
{
    int T;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        int N;
        scanf("%d", &N);
        for (int i = 0; i <= N; i++) 
            dp[i] = make_pair(-1, -1);
        printf("%d %d\n", fibo(N).first, fibo(N).second);
    }
}
