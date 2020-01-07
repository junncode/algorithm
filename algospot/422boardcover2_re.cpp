#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int H, W, R, C, bckSize, maxBckNum, cashe[10][10], findMax;
bool bck[4][10][10];

void play (bool board[10][10], int bckNum)
{
    
    printf("\nblkNum: %d\n", bckNum);
    printf("board ->\n");
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (board[i][j])
                printf("ㅡ");
            else
                printf("ㅁ");
        }
        printf("\n");
    }

    if (bckNum >= maxBckNum) {
        printf("pre finish\n");
        findMax = max(findMax, bckNum);
        return;
    }

    int hn = -1, wn = -1;
    for (int hh = 0; hh < H; hh++) {
        for (int ww = 0; ww < W; ww++) 
            if (board[hh][ww]) {
                hn = hh;
                wn = ww;
                break;
            }
        if (hn != -1)
            break;
    }
    if (hn == -1) {
        printf("finish\n");
        findMax = max(findMax, bckNum);
        return;
    }
    printf("hn: %d, wn: %d\n", hn, wn);

    board[hn][wn] = false;
    play(board, bckNum);
    board[hn][wn] = true;

    for (int type = 0; type < 4; type++) {
        for (int tab = 0; tab < bckNum; tab++)
            printf("\t");
        printf("type: %d\n", type);
        bool isContinue = true;
        int nR, nC, bckW, firH, firW;
        if ((type == 0) || (type == 2)) {
            nR = R; nC = C;
        }
        else {
            nR = C; nC = R;
        }

        for (bckW = 0; bckW < nC; bckW++)
            if (!bck[type][0][bckW])
                break;
        firH = hn; firW = wn - bckW;
        for (int i = firH; i < firH+nR; i++) {
            for (int j = firW; j < firW+nC; j++) {
                if ((i < 0) || (i >= H) || (j < 0) || (j >= W)) {
                    isContinue = false;
                    break;
                }
                else {
                    if (!bck[type][i-firH][j-firW] && !board[i][j]) {
                        isContinue = false;
                        break;
                    }
                }
            }
            if (!isContinue)
                break;
        }
        if (isContinue) {
            for (int i = firH; i < firH+nR; i++)
                for (int j = firW; j < firW+nC; j++)
                    if (!bck[type][i-firH][j-firW])
                        board[i][j] = false;
            play(board, bckNum+1);
            for (int i = firH; i < firH+nR; i++)
                for (int j = firW; j < firW+nC; j++)
                    if (!bck[type][i-firH][j-firW])
                        board[i][j] = true;
        }
    }
}

int main (void)
{
    int T;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        scanf("%d %d %d %d", &H, &W, &R, &C);
        bool board[10][10];
        findMax = -1;
        int blankNum = 0;
        bckSize = 0;
        memset(board, false, sizeof(board));
        for (int hn = 0; hn < H; hn++) {
            char tmp[11];
            scanf("%s", tmp);
            for (int wn = 0; wn < W; wn++) 
                if (tmp[wn] == '.') {
                    board[hn][wn] = true;
                    blankNum++;
                }
        }
        memset(bck, true, sizeof(bck));
        for (int rn = 0; rn < R; rn++) {
            char tmp[11];
            scanf("%s", tmp);
            for (int cn = 0; cn < C; cn++) 
                if (tmp[cn] == '#') {
                    bck[0][rn][cn] = false;
                    bck[1][C-1-cn][rn] = false;
                    bck[2][R-1-rn][C-1-cn] = false;
                    bck[3][cn][R-1-rn] = false;
                    bckSize++;
                }
        }
        maxBckNum = blankNum / bckSize;

        printf("\n");
        printf("board ->\n");
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (board[i][j])
                    printf("ㅡ");
                else
                    printf("ㅁ");
            }
            printf("\n");
        }

        printf("block ->\n");
        printf("1 ->\n");
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (bck[0][i][j])
                    printf("ㅡ");
                else
                    printf("ㅁ");
            }
            printf("\n");
        }
        printf("2 ->\n");
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < R; j++) {
                if (bck[1][i][j])
                    printf("ㅡ");
                else
                    printf("ㅁ");
            }
            printf("\n");
        }
        printf("3 ->\n");
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (bck[2][i][j])
                    printf("ㅡ");
                else
                    printf("ㅁ");
            }
            printf("\n");
        }
        printf("4 ->\n");
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < R; j++) {
                if (bck[3][i][j])
                    printf("ㅡ");
                else
                    printf("ㅁ");
            }
            printf("\n");
        }

        memset(cashe, -1, sizeof(cashe));
        //play(board, 0);
        printf("%d\n", findMax);
    }
}
