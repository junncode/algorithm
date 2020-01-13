#include <iostream>
#include <algorithm>
using namespace std;

const int max_n = 1e5 + 1;
int N, Q;
int road[max_n];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> Q;
	for (int i = 0; i < N; i++)
		cin >> road[i];
	sort(road, road + N);

	for (int i = 0; i < Q; i++)
	{
		int l, r;
		cin >> l >> r;

		auto lt = lower_bound(road, road + N, l);
		auto rt = lower_bound(road, road + N, r+1);
	 
		cout << (rt - lt) << "\n";
	}

    return 0;
}
