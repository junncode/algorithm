#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
 
typedef long long ll;
 
ll n, k, Q;
 
ll find_depth (ll x) {
    ll mod = 1;
    ll depth = 0;
    while (x > 0) {
        x -= mod;
        mod *= k;
        depth++;
    }
    return depth;
}
 
int main() {
    scanf("%lld %lld %lld", &n, &k, &Q);
    if (k == 1) {
        ll u, v;
        while (Q--) {
            scanf("%lld%lld", &u, &v);
            printf("%lld\n", u > v ? u - v : v - u);
        }
        return 0;
    }

    while (Q--) {
        ll u, v, d1, d2, ans = 0;
        scanf("%lld %lld", &u, &v);
        d1 = find_depth(u);
        d2 = find_depth(v);
        while (d1 > d2) {
            u = (u + k - 2) / k;
            d1--;
            ans++;
        }
        while (d2 > d1) {
            v = (v + k - 2) / k; 
            d2--;
            ans++;
        }
        while (u != v) {
            u = (u + k - 2) / k;
            v = (v + k - 2) / k;
            ans += 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

