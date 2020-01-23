#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll N, k;
	scanf("%lld %lld", &N, &k);
	
	if (N > k) {
		printf("1\n");
		return 0;
	}
	
	ll ans = k / N;
	if ((k % N) != 0)
		ans ++;
	printf("%lld\n", ans);
	
	return 0;
}
