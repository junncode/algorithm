#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int K, cashe[15][1<<15], overlap[15][15];  // 1<<15 = 2^15
vector<string> frag;

void calcOverlap (void)
{
    for (int i = 0; i < K-1; i++) {
        for (int j = i+1; j < K; j++) {
            
        }
    }
}

int restore (int last, int used)
{
    if (used == (1<<K) - 1)
        return 0;

    int& ret = cashe[last][used];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int next = 0; next < K; next++) {
        if ((used & (1<<next)) == 0) {
            int cand = overlap[last][next] + restore(next, used + (1<<next));
            ret = max(ret, cand);
        }
    }
    return ret;
}

string reconstruct (int last, int used)
{
    if (used == (1<<K)-1)
        return "";

    for (int next = 0; next < K; next++) {
        if (used & (1<<next))
            continue;
        int ifUsed = restore(next, used + (1<<next)) + overlap[last][next];
        if (restore(last, used) == ifUsed)
            return (frag[next].substr(overlap[last][next]) + reconstruct(next, used + (1<<next)));
    }
    return "NEVER";
}

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        scanf("%d", &K);
        frag.clear();
        for (int k = 0; k < K; k++) {
            string tmp;
            cin >> tmp;
            frag.push_back(tmp);
        }
        memset(cashe, -1, sizeof(cashe));
    }
}
