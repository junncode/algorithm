#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, W, w[100], s[100], cashe[100][1000];
vector<string> thing;
vector<int> picked;

int calc (int idx, int remW)
{
    if (idx == N)
        return 0;

    int& ret = cashe[idx][remW];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    if (remW - w[idx] >= 0) 
        ret = max(ret, s[idx] + calc(idx+1, remW - w[idx]));
    ret = max(ret, calc(idx+1, remW));
    return ret;
}

void reconst (int idx, int remW, vector<int>& picked)
{
    if (idx == N)
        return;

    if (calc(idx, remW) == calc(idx+1, remW))
        reconst(idx+1, remW, picked);
    else {
        picked.push_back(idx);
        reconst(idx+1, remW - w[idx], picked);
    }
}

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        scanf("%d %d", &N, &W);
        thing.clear();
        for (int tn = 0; tn < N; tn++) {
            string tmp;
            cin >> tmp;
            thing.push_back(tmp);
            scanf("%d %d", &w[tn], &s[tn]);
        }

        memset(cashe, -1, sizeof(cashe));
        calc(0, W);
        picked.clear();
        reconst(0, W, picked);
        sort(picked.begin(), picked.end());
        printf("%d %lu\n", calc(0, W), picked.size());
        for (int i = 0; i < picked.size(); i++) 
            cout << thing[picked[i]] << endl;
    }
    return 0;
}
