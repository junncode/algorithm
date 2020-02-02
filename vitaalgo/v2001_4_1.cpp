#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct USER{
	int n, p;
};
int main(){
	int n; scanf("%d", &n);
	queue<USER> q;
	vector<int> p;
	for(int i = 0; i<n; ++i){
		int a, b; scanf("%d %d", &a, &b);
		q.push({a, b});
		p.push_back(b);
	}
	//우선순위를 내림차순으로 정렬
	sort(p.begin(), p.end());
	reverse(p.begin(), p.end());
	int c; scanf("%d", &c);
	int ans = 1;
	while(q.size()){
		USER cur = q.front(); q.pop();
		if(cur.p == p.back()){	//현재 큐의 맨 앞에 있는 사람의 우선순위가 가장 높은 경우
			if(cur.n == c){
				printf("%d", ans); return 0;
			}
			++ans;
			p.pop_back();
		}
		else{	//뒤에 더 높은 우선순위를 갖는 사람이 있는 경우
			q.push(cur);
		}
	}
}
