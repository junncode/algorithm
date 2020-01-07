#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

string W, N, ans[50];
int num, cashe[101][101], cnt;

bool check (int w, int n)
{
    int& ret = cashe[w][n];

    if (ret != -1)  // 이미 검사한 부분
        return ret;

    if (w < W.size() && n < N.size() && (W[w] == '?' || W[w] == N[n]))  // 글자가 대응
        return ret = check(w+1, n+1);

    // 글자가 대응이 안됌
    // 1. wildcard의 문자가 끝남 -> 검사문자도 끝난 것이면 true
    if (w == W.size()) 
        return ret = (n == N.size());
    // 2. wildcard에 * 등장 -> wildcard의 다음문자로 검사 or 검사문자의 현재위치 무시, 다음위치로
    if (W[w] == '*') 
        if (check(w+1, n) || (n < N.size() && check(w, n+1)))
            return ret = 1;
    // 3. 그 외의 경우 대응되는 문자열이 아님
    return ret = 0;
}

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        cin >> W;
        scanf("%d", &num);
        cnt = 0; 
        for (int fn = 0; fn < num; fn++) {
            cin >> N;
            memset(cashe, -1, sizeof(cashe));
            if (check(0, 0)) 
                ans[cnt++] = N;
        }
        sort(ans, ans + cnt);
        for (int i = 0; i < cnt; i++) 
            cout << ans[i] << endl;
    }
}
