#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int N;
int map[10][10];
int M;

void cal (int start, int cur, int sum, bool visit[]) {
	if (start == cur) {
		M = max(M, sum);
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (i != cur && !visit[i] && map[cur][i] > 0) {
			visit[i] = true;
			cal(start, i, sum+map[cur][i], visit);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			map[i][j] = tmp;
		}
	
	int ans = 0;
	for (int i = 0; i < N; i++) {
		M = 0;
		bool visit[10];
		memset(visit, false, sizeof(visit));
		for (int j = 0; j < N; j++) {
			if (i != j && map[i][j] > 0) {
				visit[j] = true;
				cal(i, j, map[i][j], visit);
				visit[j] = false;
			}
		}
		ans = max(ans, M);
	}
	printf("%d\n", ans);
	return 0;
}
