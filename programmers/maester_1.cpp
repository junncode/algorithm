#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool exist[200005];

int solution(vector<int> nums)
{
	int answer = 0;
    
    sort(nums.begin(), nums.end());
    memset(exist, false, sizeof(exist));
    
    for (int i = 0; i < nums.size(); i++) {
     	if (!exist[nums[i]]) {
            exist[nums[i]] = true;
            answer++;
        }
    }
    
    if (answer > (nums.size() / 2))
        answer = nums.size() / 2;   
	return answer;
}
