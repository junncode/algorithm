#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int N, M;
bool visited[105][105];

int bfs (vector<vector<int> > &map) {
    queue<pair<int, int > > q;
    q.push(make_pair(0, 0));
    
    int result = 2;
    while (!q.empty()) {
        int curSize = q.size();
        for (int i = 0; i < curSize; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int j = 0; j < 4; j ++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                
                if (0 <= nx && nx < map.size() && 0 <= ny && ny < map[0].size()) {
                    if (nx == map.size()-1 && ny == map[0].size()-1)
                        return result;
                    
                    else if (map[nx][ny] && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        result++;
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
	int answer;
    
    memset(visited, false, sizeof(visited));
    
    answer = bfs(maps);
    
	return answer;
}
