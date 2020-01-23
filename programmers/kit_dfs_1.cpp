#include <cstdio>
#include <string>
#include <vector>
using namespace std;

vector<int> ns;
int tar;
int ans = 0;

void dfs (int idx, int sum) {
    if (idx == ns.size()) {
        if (sum == tar)
            ans++;
        return;
    }
    dfs(idx+1, sum - ns[idx]);
    dfs(idx+1, sum + ns[idx]);
    return;
}

int solution(vector<int> numbers, int target) {
    for (int i = 0; i < numbers.size(); i++)
        ns.push_back(numbers[i]);
    tar = target;
    
    dfs(0, 0);
    
    return ans;
}
