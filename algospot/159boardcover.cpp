#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

int H = 0, W = 0;  // 1 <= H,W <= 20
bool board[20][20];

const int dh[8] = {0, 1, 0, 1, 1, 1, 1, 1};
const int dw[8] = {1, 0, 1, 1, 0, 1, -1, 0};

int makeL(bool curBrd[20][20], int setCnt)
{
    /*
    printf("\n%d\n", setCnt);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (curBrd[i][j])
                printf("0 ");
            else
                printf("1 ");
        }
        printf("\n");
    }
    */
    int firBlankH = -1;
    int firBlankW = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (curBrd[i][j]) {
                firBlankH = i;
                firBlankW = j;
                break;
            }
        }
        if (firBlankH != -1)
            break;
    }
    if (firBlankH == -1)
        return 1;
    else {
        if (setCnt <= 0) {
            return 0;
        }
    }

    int ret = 0;
    int nextH1 = -1, nextW1 = -1;
    int nextH2 = -1, nextW2 = -1;
    //printf("firBlankH: %d, firBlankW: %d\n", firBlankH, firBlankW);
    for (int chk = 0; chk < 4; chk++) {
        nextH1 = firBlankH + dh[chk*2];
        nextW1 = firBlankW + dw[chk*2];
        nextH2 = firBlankH + dh[chk*2+1];
        nextW2 = firBlankW + dw[chk*2+1];
        if ((nextH1 >= 0) && (nextH1 < H) && (nextW1 >= 0) && (nextW1 < W) && (nextH2 >= 0) && (nextH2 < H) && (nextW2 >= 0) && (nextW2 < W)) {  // 범위 확인
            if (curBrd[nextH1][nextW1] && curBrd[nextH2][nextW2]) {
                curBrd[firBlankH][firBlankW] = curBrd[nextH1][nextW1] = curBrd[nextH2][nextW2] = false;
    //            printf("h1: %d w1: %d, h2: %d w2: %d\n", nextH1, nextW1, nextH2, nextW2);
                ret += makeL(curBrd, setCnt - 1);
                curBrd[firBlankH][firBlankW] = curBrd[nextH1][nextW1] = curBrd[nextH2][nextW2] = true;
            }
        }
    }
    //printf("%d >> return : %d\n", setCnt, ret);

    return ret;
}

int main (void)
{
    int C = 0;
    scanf("%d", &C);

    bool curBrd[20][20];
    for (int testCnt = 0; testCnt < C; testCnt++) {
        scanf("%d %d", &H, &W);

        memset(curBrd, false, sizeof(curBrd));
        char tmp[21];
        int blankCnt = 0;
        for (int h = 0; h < H; h++) {
            scanf("%s", tmp);
            for (int w = 0; w < W; w++) {
                if (tmp[w] == '.') {
                    curBrd[h][w] = true;
                    blankCnt++;
                }
            }
        }
/*
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (curBrd[i][j])
                    printf("0 ");
                else
                    printf("1 ");
            }
            printf("\n");
        }
*/        
        if (((blankCnt % 3) != 0) || (blankCnt == 0)) {
            printf("0\n");
        }
        else {
            int setCnt = blankCnt / 3;
            printf("%d\n", makeL(curBrd, setCnt));
        }
    }

    return 0;
}
