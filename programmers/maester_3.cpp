#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

vector<string> arr;
int dp[203][203][2];
int dpMin (int from, int to);
int dpMax (int from, int to);

int dpMin (int from, int to) {
    if (from == to) 
        return atoi(arr[from].c_str());
    
    int& ret = dp[from][to][1];
    if (ret != 987654321) 
        return ret;
    
    for (int i = 0; i < (to - from) / 2; i++) {
        int idx = from + i * 2 + 1;
        if (arr[idx] == "+") 
            ret = min(ret, dpMin(from, idx-1) + dpMin(idx+1, to));
        else
            ret = min(ret, dpMin(from, idx-1) - dpMax(idx+1, to));
    }
    return ret;
}

int dpMax (int from, int to) {
    if (from == to) 
        return atoi(arr[from].c_str());
    
    int& ret = dp[from][to][0];
    if (ret != -987654321) 
        return ret;
    
    for (int i = 0; i < (to - from) / 2; i++) {
        int idx = from + i * 2 + 1;
        if (arr[idx] == "+") 
            ret = max(ret, dpMax(from, idx-1) + dpMax(idx+1, to));
        else
            ret = max(ret, dpMax(from, idx-1) - dpMin(idx+1, to));
    }
    return ret;
}

int solution(vector<string> tmp)
{
	arr.resize(tmp.size());
    copy(tmp.begin(), tmp.end(), arr.begin());
    
    for (int i = 0; i < 203; i++) {
        for (int j = 0; j < 203; j++) {
            dp[i][j][0] = -987654321;
            dp[i][j][1] = 987654321;
        }
    }
    
    int answer = dpMax(0, arr.size()-1);
    
	return answer;
}
