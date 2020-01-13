#include <iostream>
#include <queue>
#include <string>
#include <cstring> //memset
using namespace std;

const int MAX = 100;

typedef struct
{
    int y, x;
}Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int N;
string graph[MAX];
bool visited[MAX][MAX];

void BFS(int y, int x, bool colorBlind) {
    char search = graph[y][x]; //해당 칸의 색깔
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    visited[y][x] = 1;

    while (!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = curY + moveDir[i].y;
            int nextX = curX + moveDir[i].x;

            if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N) { //범위 내에 있어야한다
                if (colorBlind == false) { //적록색맹이 아니라면
                    if (graph[nextY][nextX] == search && !visited[nextY][nextX]) { //해당 색깔 칸만 찾는다
                        visited[nextY][nextX] = true;
                        q.push(make_pair(nextY, nextX));
                    }
                }
                else if (colorBlind == true) { //적록색맹이라면
                    if (search == 'R' || search == 'G') { //빨간색과 초록색을 같은 색깔로 인지
                        if (!visited[nextY][nextX] && (graph[nextY][nextX] == 'R' || graph[nextY][nextX] == 'G')) {
                            visited[nextY][nextX] = true;
                            q.push(make_pair(nextY, nextX));
                        }
                    }
                    else if (search == 'B') { //파란색은 인지 가능
                        if (!visited[nextY][nextX] && (graph[nextY][nextX] == search)) {
                            visited[nextY][nextX] = true;
                            q.push(make_pair(nextY, nextX));
                        }
                    }
                }
            }
        }
    }
}

int main(void)
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> graph[i];

    int cnt = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if (visited[i][j] == false) {
                BFS(i, j, false);
                cnt++;
            }
    cout << cnt << " ";

    memset(visited, false, sizeof(visited));
    cnt = 0;
    for(int i=0; i<N; i++)
        for (int j = 0; j < N; j++)
            if(visited[i][j]==false) {
                BFS(i, j, true);
                cnt++;
            }
    cout << cnt << endl;

    return 0;
}
