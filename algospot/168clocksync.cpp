#include <cstdio>
#include <algorithm>
using namespace std;

#define INF 987654321

char sw[10][17] = {
    "1110000000000000",
    "0001000101010000",
    "0000100000100011",
    "1000111100000000",
    "0000001110101000",
    "1010000000000011",
    "0001000000000011",
    "0000110100000011",
    "0111110000000000",
    "0001110001000100"
};
int cnt = INF;

bool isAll12(int clocks[16]) 
{
    for (int i = 0; i < 16; i++) {
        if (clocks[i] != 0)
            return false;
    }
    return true;
}

void make12(int clocks[16], int swiIdx, int curCnt) 
{
    /*printf("<swiIdx: %d, curCnt: %d>\n", swiIdx, curCnt);
    for (int i = 0; i < 16; i++) {
        printf("%d ", clocks[i]);
    }
    printf("\n----------------------------------------\n");
*/
    if (isAll12(clocks)) {
        //printf("swiIdx: %d, curCnt: %d, finish!\n", swiIdx, curCnt);
        cnt = min(cnt, curCnt);
        return;
    }
    if (swiIdx > 9) {
        return;
    }
    
    for (int i = 0; i < 4; i++) {  // 스위치 3번 누르기
        //printf("switch %d x %d\n", swiIdx, i);
        make12(clocks, swiIdx+1, curCnt+i);
        for (int j = 0; j < 16; j++) {  
            if (sw[swiIdx][j] == '1') 
                clocks[j] = (clocks[j] + 1) % 4;
        }
    }

    return;
}

int main(void)
{
    int C = 0;
    scanf("%d", &C);
    int tmp;
    for (int testCnt = 0; testCnt < C; testCnt++) {
        int clocks[16] = {0,};
        cnt = INF;
        for (int clkCnt = 0; clkCnt < 16; clkCnt++) {
            scanf("%d ", &tmp);
            if (tmp == 12) 
                clocks[clkCnt] = 0;
            else if (tmp == 3)
                clocks[clkCnt] = 1;
            else if (tmp == 6)
                clocks[clkCnt] = 2;
            else 
                clocks[clkCnt] = 3;
        }

        /*for (int i = 0; i < 16; i++) {
            printf("%d ", clocks[i]);
        }
        printf("\n----------------------------------------\n");
        */
        make12(clocks, 0, 0);
        if (cnt == INF)
            printf("-1\n");
        else 
            printf("%d\n", cnt);
    }
}
