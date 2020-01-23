#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> answer;
vector<bool> used;
bool isFind = false;

bool cmp (vector<string> a, vector<string> b) {
    return a[1] < b[1];
}

void dfs (vector<vector<string>> &tickets, string from, int idx) {
    if (isFind)
        return;
    
    if (idx == tickets.size()) {
    	isFind = true;
        //cout << "true" << endl;
        return;
    }
    
    for (int i = 0; i < tickets.size(); i++) {
        string to;
        if (isFind)
            return;
        if (tickets[i][0] == from && !used[i]) {
            to = tickets[i][1];
            answer[idx+1] = to;
            used[i] = true;
            //cout << "["<<idx<<"]" << "from: " << from << ", to: " << to << endl;
        	dfs(tickets, to, idx+1);
            used[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), cmp);
    answer.resize(tickets.size()+1);
    used.resize(tickets.size());
    answer[0] = "ICN";
    dfs(tickets, "ICN", 0);
    
    return answer;
}
