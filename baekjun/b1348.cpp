#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100;
const int INF = 987654321;

int moveX[4] = { 0,0,-1,1 };
int moveY[4] = { 1,-1,0,0 };
int R, C, carCnt, parkCnt, mid, cost[205][205],matchA[205],matchB[205];
bool visit[205];

char board[51][51];
vector<pair<int, int > > car, park;
vector<int> adj[205];

bool dfs(int cur) {
	visit[cur] = true;
	for (int next : adj[cur]) {
		if (cost[cur][next] <= mid && (matchB[next] == -1 || !visit[matchB[next]] && dfs(matchB[next]))) {
			matchA[cur] = next;
			matchB[next] = cur;
			return true;
		}
	}
	return false;
}



int main(){
// 입력 작업
	scanf("%d%d", &R, &C); getchar();
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%1c", &board[i][j]);
			if (board[i][j] == 'C') {
				car.push_back(make_pair(i,j));
			}
			else if (board[i][j] == 'P') {
				park.push_back(make_pair(i,j));
			}
		}
		getchar();
	}

// 불가능한 경우 탐색
	carCnt = car.size();
	parkCnt = park.size();
	if (carCnt > parkCnt) {
		cout << -1 << endl;
		return 0;
	}
	if (carCnt == 0) {
		cout << 0 << endl;
		return 0;
	}

// 차 마다 거리 검사
	for (int i = 0; i < carCnt; i++) {
		int dist[51][51] = { 0, };
		bool visit[51][51] = { false, };
		int fromX = car[i].first, fromY = car[i].second;
		
		for (int k = 0; k < 51; k++)
			for (int m = 0; m < 51; m++) 
				dist[k][m] = INF;

		queue<pair<int, int > > q;
		q.push(make_pair(fromX,fromY));
		visit[fromX][fromY] = 1;
		dist[fromX][fromY] = 0;

// BFS
		while (!q.empty()) {
			pair<int, int> p = q.front();
            q.pop();
			int cx = p.first, cy = p.second;

			for (int i = 0; i < 4; i++) {
				int nx = cx + moveX[i];
				int	ny = cy + moveY[i];

				if (nx < 0 || ny < 0 || nx >= R || ny >= C) 
                    continue;
				if (!visit[nx][ny] && board[nx][ny] != 'X') {
					visit[nx][ny] = true;
					dist[nx][ny] = dist[cx][cy] + 1;
					q.push(make_pair(nx,ny));
				}
			}
		} 

		for (int j = 0; j < parkCnt; j++) {
			int parkX = park[j].first, parkY = park[j].second;
			
			if (dist[parkX][parkY] != INF) {
				adj[i].push_back(MAXN + j);
				adj[MAXN + j].push_back(i);
				cost[i][MAXN + j] = dist[parkX][parkY];
				cost[MAXN + j][i] = -dist[parkX][parkY];
			}
		}
	}

	int match = 0;
	memset(matchA, -1, sizeof(matchA));
	memset(matchB, -1, sizeof(matchB));
	mid = INF;

	for (int i = 0; i < carCnt; i++) {
		if (matchA[i] == -1) {
			memset(visit, 0, sizeof(visit));
			if (dfs(i)) 
                match++;
		}
	}
	if (match != carCnt) {
		cout << -1 << endl;
		return 0;
	}

	int lo = 0, hi = R * C;
	while (lo + 1 < hi) {
		mid = (lo + hi) / 2;
		match = 0;
		memset(matchA, -1, sizeof(matchA));
		memset(matchB, -1, sizeof(matchB));
		for (int i = 0; i < carCnt; i++) {
			if (matchA[i] == -1) {
				memset(visit, 0, sizeof(visit));
				if (dfs(i)) match++;
			}
		}
		if (match == carCnt) hi = mid;
		else lo = mid;
	}
	cout << hi << endl;
}

