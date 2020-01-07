#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int C = 0;  // C <= 50
int n = 0;  // 2 <= n <= 10
int m = 0;  // 0 <= m <= n(n-1)/2
bool frd[10][10];

int makeFrd(bool grp[10]);

int main(void)
{
    bool grp[10];
    scanf("%d", &C); // 테스트 케이스 입력
    for (int testCnt = 0; testCnt < C; testCnt++) {
        scanf("%d %d", &n, &m);  // 학생의 수, 친구 쌍의 수 입력
        
        memset(frd, false, sizeof(frd));
        memset(grp, false, sizeof(grp));
        for (int frdCnt = 0; frdCnt < m; frdCnt++) {
            int f1, f2;
            scanf("%d %d", &f1, &f2);
            frd[f1][f2] = frd[f2][f1] = true;
        }

        printf("%d\n", makeFrd(grp));
    }
    return 0;
}

int makeFrd(bool grp[10]) 
{
    int firAlone = -1;
    for (int i = 0; i < n; i++) 
        if (!grp[i]) {
            firAlone = i;
            break;
        }
    if (firAlone == -1) {
        return 1;
    }
    
    //printf("firAlone: %d\n", firAlone);
    int ret = 0;
    for (int i = firAlone + 1; i < n; i++) {
        if (!grp[i] && frd[firAlone][i]) {
            grp[firAlone] = true;
            grp[i] = true;
            //printf("%d - %d friend\n", firAlone, i);
            ret += makeFrd(grp);
            grp[firAlone] = false;
            grp[i] = false;
        }
    }
    return ret;
}
