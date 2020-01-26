#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> exist;
	int tmp;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &tmp);
		exist.push_back(tmp);
	}
	
	int ans = 0, f, idx;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &f);
		for (int j = 0; j < 4; j++) {
			if (exist[j] == f)
				ans++;
		}
	}
	printf("%d\n", 5 - ans);
	
	return 0;
}
