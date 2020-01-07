#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int N, allLen;
priority_queue< int, vector<int>, greater<int> > num;

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        scanf("%d", &N);
        allLen = 0;
        while (num.size() != 0) 
            num.pop();
        for (int nn = 0; nn < N; nn++) {
            int tmp;
            scanf("%d", &tmp);
            num.push(tmp);
            allLen += tmp;
        }

        if (num.size() == 1)
            printf("0\n");
        int ans = 0;
        while (1) {
            if (num.top() == allLen)
                break;

            int t1, t2;
            t1 = num.top(); num.pop();
            t2 = num.top(); num.pop();
            ans += (t1 + t2);
            num.push(t1 + t2);
        }
        printf("%d\n", ans);
    }
    return 0;
}
