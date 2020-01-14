#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
 
#define endl "\n"
#define MAX 300
using namespace std;
 
int N, M;
int map[MAX][MAX];
int tempMap[MAX][MAX];
bool visited[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
void BFS(int a, int b)
{
    queue<pair<int, int > > q;
    q.push(make_pair(a, b));
    visited[a][b] = true;
 
    while (q.empty() == 0)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
                if (visited[nx][ny] == false && map[nx][ny] != 0) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
        }
    }
}
 
int melt(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
 
        if (map[nx][ny] == 0) 
            cnt++;
    }
    return cnt;
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    int year = 0;
    while (1)
    {
        int landCnt = 0;
        memset(visited, false, sizeof(visited));
        memset(tempMap, 0, sizeof(tempMap));
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (map[i][j] != 0 && visited[i][j] == false) {
                    landCnt++;
                    BFS(i, j);
                }
        if (landCnt >= 2) { 
            cout << year << endl; 
            break; 
        }
        else if (landCnt == 0) { 
            cout << 0 << endl; 
            break; 
        }
 
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (map[i][j] != 0) {
                    tempMap[i][j] = map[i][j] - melt(i, j);
                    if (tempMap[i][j] < 0) 
                        tempMap[i][j] = 0;
                }
 
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                map[i][j] = tempMap[i][j];
        //copy(&tempMap[0][0], &tempMap[0][0] + N * M, &map[0][0]);

        year++;
    }
    return 0;
}

