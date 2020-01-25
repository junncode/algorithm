#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int cal (string s, int lev) {
    int ret = s.size();
    int cur = 0;
    int chk = lev;
    int t;
    if ((s.size() % lev) == 0)
        t = s.size() / lev - 1;
    else
        t = s.size() / lev;
    
    //cout <<"["<<lev<<"] times: "<<t<<endl;
    int checking = 1;
    for (int i = 0; i < t; i++) {
        //cout <<"["<<lev<<"]"<<"cur: "<<cur<<", chk: "<<chk<<" = "<<s.substr(cur,lev);
        while (s.substr(cur, lev) == s.substr(chk, lev)) {
            //cout<< "  +";
            ret -= lev;
            checking++;
            chk += lev;
            i++;
        }
        cur = chk;
        chk = cur + lev;
        if (checking > 1)
            ret += to_string(checking).size();
        checking = 1;
        //cout<<endl;
    }
    //cout<<"return: "<<ret<<endl;
    return ret;
}

int solution(string s) {
    int len = s.size();
    int answer = len;
    
    int m = s.size() / 2;
    for (int i = 1; i <= m; i++) {
        answer = min(answer, cal(s, i));
        //cout<<endl;
    }
    return answer;
}
