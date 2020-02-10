#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int N;
bool map[105][105];
int lCnt = 0;
int land[105][105];
bool visit[105][105];

void dfs (int lc, int x, int y) {
    land[x][y] = lc;
    visit[x][y] = true;
    
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (0 <= nx && nx < N && 0 <= ny && ny < N) 
            if (map[nx][ny] && !visit[nx][ny]) 
                dfs(lc, nx, ny);
    }
}

int bfs (int cur) {
    queue<pair<int, int> > q;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            if (land[i][j] == cur) {
                q.push(make_pair(i, j));
                visit[i][j] = true;
            }
    
    int ret = -1;
    while (!q.empty()) {
        int qs = q.size();
        ret++;
        for (int i = 0; i < qs; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                    if ((land[nx][ny] == 0) && !visit[nx][ny]) {
                        q.push(make_pair(nx, ny));
                        visit[nx][ny] = true;
                    }
                    else if ((land[nx][ny] != 0) && (land[nx][ny] != cur)) 
                        return ret;
                }
            }
        }
    }
    return 1234;
}

int main ()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    memset(land, 0, sizeof(land));
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            if (map[i][j] && !visit[i][j]) {
                lCnt++;
                dfs(lCnt, i, j);
            }
    
    int ans = 1234;
    for (int i = 1; i < lCnt; i++) {
        memset(visit, false, sizeof(visit));
        ans = min(ans, bfs(i));
    }
    printf("%d\n", ans);
    return 0;
}   
