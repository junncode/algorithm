#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int > > works;

bool cmp (pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second)
		return true;
	return false;
}

int main() {
	cin >> N;
	int s, e;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		works.push_back(make_pair(s, e));
	}
	sort(works.begin(), works.end(), cmp);

	int cur = 0, ans = 0;
	for (int i = 0; i < N; i++) {
		if (works[i].first >= cur) {
			ans++;
			cur = works[i].second;
		}
	}
	cout << ans << endl;
	return 0;
}
