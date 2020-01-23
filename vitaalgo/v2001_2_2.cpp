#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector <int> ns, ms;

int main() {
	
	int N, M, tmp;
	ll sumN = 0, sumM = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		ns.push_back(tmp);
		sumN += tmp;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &tmp);
		ms.push_back(tmp);
		sumM += tmp;
	}
	
	if (sumN != sumM) {
		printf("-1\n");
		return 0;
	}
	
	int ni = 0, mi = 0;
	sumN = 0; sumM = 0;
	int ans = 0;
	while (ni < N) {
		ans++;
		sumN = ns[ni++]; sumM = ms[mi++];
		while (sumN != sumM) {
			if (sumN < sumM)
				sumN += ns[ni++];
			else
				sumM += ms[mi++];
		}
	}
	printf("%d\n", ans);
	return 0;
}
