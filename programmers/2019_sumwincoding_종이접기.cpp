#include <string>
#include <vector>

using namespace std;
vector<int> answer;

int pow2 (int a) {
    int ret = 1;
    for (int i = 0; i < a; i++)
        ret *= 2;
    return ret;
}

void dfs (int idx, int lev, bool flag) {
    if (flag)
        answer[idx] = 1;
    else
        answer[idx] = 0;
    
    if ((idx % 2) == 0) 
        return;
    
    dfs(idx - lev, lev/2, false);
    dfs(idx + lev, lev/2, true);
    return;
}

vector<int> solution(int n) {
    int size = pow2(n);
    answer.resize(size-1);
    
    dfs((size/2)-1, (size/2)/2, false);
    
    return answer;
}
