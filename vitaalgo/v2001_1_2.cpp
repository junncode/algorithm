#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef long long ll;

vector<pair<int, int > > point;

int main() {
	
	int N;
	scanf("%d", &N);
	for (int pn = 0; pn < N; pn++) {
		ll nx, ny;
		scanf("%lld %lld", &nx, &ny);
		point.push_back(make_pair(nx, ny));
	}
	
	ll ans = 0;
	for (int i = 1; i < N-1; i++) 
		ans += (point[i].first - point[0].first) * (point[i+1].second - point[0].second) - (point[i+1].first - point[0].first) * (point[i].second - point[0].second);
	
	ans = abs(ans);
	ans = (ans / 2) + (ans % 2);
	printf("%lld\n", ans);
	return 0;
}
