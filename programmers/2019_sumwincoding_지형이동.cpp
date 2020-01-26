#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

bool visit[305][305];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int landCnt = 0;
int landH[305][305];
int markLand[305][305];
int N, M, H;
int answer = 987654321;

void dfs (vector<vector<int>> &land, int x, int y) {
    markLand[x][y] = landCnt;
    int nx, ny;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i]; ny = y + dy[i];
        if (0 <= nx && nx < N && 0 <= ny && ny < M) {
            if (abs(land[nx][ny] - land[x][y]) <= H && !visit[nx][ny]) {
                visit[nx][ny] = true;
                dfs(land, nx, ny);
            }
        }
    }
}

void chkH (vector<vector<int>> &land, int chk) {
    vector<pair<int, int> > pot;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            if (markLand[i][j] == chk) 
                pot.push_back(make_pair(i, j));
    
    int x, y, nx, ny;
    for (int i = 0; i < pot.size(); i++) {
        x = pot[i].first; y = pot[i].second;
        for (int j = 0; j < 4; j++) {
            nx = x + dx[j]; ny = y + dy[j];
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                int nl = markLand[nx][ny];
            	if (nl != chk) {
                    int need = abs(land[nx][ny] - land[x][y]);
                	landH[chk-1][nl-1] = min(landH[chk-1][nl-1], need);
                }
            }
        }
    }
}

void findMin (vector<bool> fm, int idx, int sum) {
    bool isFin = true;
    for (int i = 0; i < fm.size(); i++) 
        if (!fm[i])
            isFin = false;
    if (isFin) {
        answer = min(answer, sum);
        return;
    }
    
    for (int i = idx + 1; i < landCnt; i++) {
        if (landH[idx][i] != 987654321) {
        	fm[i] = true;
        	findMin(fm, i, sum+landH[idx][i]);
            fm[i] = false;
        }
    }
}

int solution(vector<vector<int>> land, int height) {
    
    N = land[0].size(); M = land.size(); H = height;
    memset(visit, false, sizeof(visit));
    memset(markLand, 0, sizeof(markLand));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visit[i][j]) {
                landCnt++;
                dfs(land, i, j);
            }
        }
    }
    
    for (int i = 0; i < landCnt; i++) 
        for (int j = 0; j < landCnt; j++) 
            landH[i][j] = 987654321;
    for (int i = 0; i < landCnt; i++) 
        chkH(land, i+1);
    
    for (int i = 0; i < landCnt; i++)  {
        for (int j = 0; j < landCnt; j++) {
            printf("%d ", landH[i][j]);
        }
        printf("\n");
    }
    
    vector<bool> fm(305);
    memset(fm, false, sizeof(fm));
    fm[0] = true;
    findMin(fm, 0, 0);
    
    return answer;
}
