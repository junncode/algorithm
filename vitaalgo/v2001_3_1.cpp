#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct POS{
	int x, y;
};
//x, y에서 모임을 한다고 했을 때 이동하는 횟수의 합을 구하는 함수
int go(vector<POS> & seq, int x, int y){
	int res = 0;
	for(int i = 0; i<seq.size(); ++i)
		res += abs(seq[i].x - x) + abs(seq[i].y - y);
	return res;
}
int main(){
	int n, m; cin >> n >> m;
	//x좌표와 y좌표를 저장할 배열
	vector<int> xx(m), yy(m);
	//x, y좌표를 합쳐서 저장할 배열
	vector<POS> seq;
	for(int i = 0; i<m; ++i){
		cin >> xx[i] >> yy[i];
		seq.push_back({xx[i], yy[i]});
	}
	//각각의 좌표를 정렬
	sort(xx.begin(), xx.end());
	sort(yy.begin(), yy.end());
	int mx, my;
	//중앙값 선택
	if(m % 2){	//홀수
		mx = xx[m/2];
		my = yy[m/2];
	}
	else{	//짝수
		mx = (xx[m / 2] + xx[m / 2 - 1]) / 2;
		my = (yy[m / 2] + yy[m / 2 - 1]) / 2;
	}
	int res = 1e9;
	//중앙값이 정수가 아닌 경우를 위해 근처 점들 탐색
	for(int i = max(1, mx - 1); i <= min(n, mx + 1); ++i)
		for(int j = max(1, my - 1); j <= min(n, my + 1); ++j)
			res = min(res, go(seq, i, j));
	cout << res;
}
