#include<iostream>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
//행렬의 곱셈을 위한 함수. 결과를 m1에 저장
void matMul(ll m1[2][2], ll m2[2][2]){
    ll res[2][2] = {0};
    for(int i = 0; i<2; ++i){
        for(int j = 0; j<2; ++j){
            for(int k = 0; k<2; ++k){
                res[i][j] += m1[i][k] * m2[k][j];
                res[i][j] %= mod;
            }
        }
    }
    for(int i = 0; i<2; ++i)
        for(int j = 0; j<2; ++j)
            m1[i][j] = res[i][j];
}

ll pow(ll n){
    ll res[2][2] = {{1, 1}, {1, 0}};
    ll mat[2][2] = {{1, 1}, {1, 0}};
    while(n){
        if(n % 2)
            matMul(res, mat);
        matMul(mat, mat);
        n /= 2;
    }
	return res[1][1];
}

int main(){
    ll n; cin >> n;
    cout << pow(n);
}
