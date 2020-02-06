#include <iostream>
#include <queue>
using namespace std;

int N, M;
vector<int> cla[100005];
bool chk[100005];
int ans = 0;

int bfs (int c) {
	int cnt = 0;
	queue<int> q;
	q.push(c);
	chk[c] = true;
	while (!q.empty()) {
		cnt++;
		int b = q.front(); q.pop();
		for (int i = 0; i < cla[b].size(); i++) {
			int a = cla[b][i];
			if (!chk[a]) {
				chk[a] = true;
				q.push(a);
			}
		}
	}
	return cnt;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cla[b].push_back(a);
	}
	
	int C;
	cin >> C;
	cout << bfs(C) << endl;
	
	return 0;
}
