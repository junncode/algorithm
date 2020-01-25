#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

int answer = -987654321;

void cal (vector<string> pm, vector<int> num) {
    if (pm.size() == 0) {
    	answer = max(answer, num[0]);
        return;
    }
    
    for (int i = 0; i < pm.size(); i++) {
        vector<string> tpm;
        vector<int> tnum;
        tpm.resize(pm.size());
        copy(pm.begin(), pm.end(), tpm.begin());
        tnum.resize(num.size());
        copy(num.begin(), num.end(), tnum.begin());
        
        if (pm[i] == "+") 
            tnum[i] = tnum[i] + tnum[i+1];
        else
            tnum[i] = tnum[i] - tnum[i+1];
        tnum.erase(tnum.begin() + i + 1);
        tpm.erase(tpm.begin() + i);
        cal(tpm, tnum);
    }
}

int solution(vector<string> arr)
{
	vector<int> num;
	vector<string> pm;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == "+" || arr[i] == "-") 
            pm.push_back(arr[i]);
        else
            num.push_back(atoi(arr[i].c_str()));
    }
    
    cal(pm, num);
    
	return answer;
}
