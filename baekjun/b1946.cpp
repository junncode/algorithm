#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main (void)
{
    vector<pair <int, int> > can;
    int T;
    scanf("%d", &T);
    for (int tn = 0; tn < T; tn++) {
        int N;
        scanf("%d", &N);
        for (int nn = 0; nn < N; nn++) {
            int pap, itv;
            scanf("%d %d", &pap, &itv);
            can.push_back(make_pair(pap, itv));
        }
        sort(can.begin(), can.end());

        int ans = 1;
        int maxSec = can[0].second;
        for (int i = 1; i < N; i++) {
            if (can[i].second < maxSec) {
                maxSec = can[i].second;
                ans++;
            }
        }
        printf("%d\n", ans);
        can.clear();
    }
}
