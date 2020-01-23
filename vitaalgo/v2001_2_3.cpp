#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<pair<int, bool > > ns;

bool cmp (pair<int, bool> a, pair<int, bool> b) {
	return a.first > b.first;
}
bool cmp2 (pair<int, bool> a, pair<int, bool> b) {
	if (a.second != b.second)
		return b.second;
	else
		return a.first > b.first;
}

int main() {
	int N, tmp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		ns.push_back(make_pair(tmp, false));
	}
	sort(ns.begin(), ns.end(), cmp);
	
	int big, small, cur, ni = 0;
	big = cur = ns[0].first;
	ns[0].second = true;
	while (cur != 1) {
		ni++;
		if (!ns[ni].second) {
			if ((big % ns[ni].first) == 0 && cur > ns[ni].first) {
				cur = ns[ni].first;
				ns[ni].second = true;
			}
		}
	}
	sort(ns.begin(), ns.end(), cmp2);
	small = ns[0].first;
	printf("%d %d\n", small, big);
	return 0;
}
