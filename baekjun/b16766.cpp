#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
 
int hi = 1000000000;
int N, M, C;
int arr[123456];

bool canRide(int x) {
    int cnt = 1;
    for (int i = 1, start = 0; i < N; i++) {
        //arr[start] + x는  도착한 버스를 처음타는 소의 기다리는 시간
        if (i - start < C && arr[i] <= arr[start] + x)
            continue;

        //버스탑승인원초과하거나 x초 대기시간 넘으면
        //버스보내고 다른버스태운다.
        cnt += 1;
        start = i;
    }
 
    return cnt <= M;
}
 
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> C;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
 
    int lo = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        //cout << "lo : " << lo << ",  mid: " << mid << ",  hi : " << hi << endl; 
        //최대 mid 초안에 모든 소들이 탑승 가능한지? 
        if (canRide(mid))
            hi = mid-1;
        else
            lo = mid+1;
    }
    cout << lo << endl;
 
    return 0;
}
