#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N;
vector<pair <int, int> > meet;

int main (void)
{
    scanf("%d", &N);
    for (int nn = 0; nn < N; nn++) {
        int fin, sta;
        scanf("%d %d", &sta, &fin);
        meet.push_back(make_pair(fin, sta));
    }

    sort(meet.begin(), meet.end());
    int cur = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        if (meet[i].second >= cur) {
            cur = meet[i].first;
            ans++;
        }
    }
    printf("%d\n", ans);
}
