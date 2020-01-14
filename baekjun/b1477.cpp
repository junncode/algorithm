#include <iostream>
#include <algorithm>
using namespace std;

int tg[100001];

int main(void) {

    int n, m, MAX;
    cin >> n >> m >> MAX;
    for (int i = 1; i <= n; ++i) 
        cin >> tg[i];
    tg[n+1] = MAX;
    sort(tg, tg + n + 2);

    int lo = 1;
    int hi = MAX-1;
    while (lo <= hi) {
        int mcnt = 0;
        int mid = (hi + lo) / 2;

        for (int i = 1; i <= n+1; ++i) 
            if (tg[i] - tg[i - 1] > mid) 
                mcnt += ((tg[i] - tg[i - 1] - 1)) / mid;

        if (mcnt > m) 
            lo = mid + 1;
        else 
            hi = mid - 1;
    }

    cout << lo << endl;
    return 0;
}
