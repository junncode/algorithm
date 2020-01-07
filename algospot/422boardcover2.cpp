#include <cstdio>
#include <cstring>
using namespace std;

int H, W, R, C, bckSize, cashe[10][10], findMax;
bool bck[10][10];

int play (bool board[10][10], int blkNum)
{
    if (blkNum < bckSize)
        return 0;

    int hn, wn;
    for (int hh = 0; hh < H, hh++) 
        for (int ww = 0; ww < W; ww++) 
            if (board[hh][ww] && (cashe[hh][ww] != 0)) {
                hn = hh; wn = ww;
                break;
            }
    
    int& ret = cashe[hn][wn];
    if (ret != -1)
        return ret;

    ret = 0;
    int bckW, firH, firW;

    // 회전 0도
    bool isContinue = true;
    for (bckW = 0; bckW < C; bckW++) 
        if (!bck[0][bckW])
            break;
    firH = hn; firW = wn-bckW;
    for (int i = firH; i < firH+R; i++) {
        for (int j = firW; j < firW+C; j++) {
            if ((i < 0) || (i >= H) || (j < 0) || (j >= W)) {
                isContinue = false;
                break;
            }
            else {
                if (!bck[i-firH][j-firW] && !board[i][j]) {
                    isContinue = false;
                    break;
                }
            }
        }
        if (!isContinue)
            break;
    }
    if (isContinue) {
        for (int i = firH; i < firH+R; i++) 
            for (int j = firW; j < firW+C; j++) 
                if (!bck[i-firH][j-firW])
                    board[i][j] = false;
        ret += play(board, blkNum-bckSize);
        for (int i = firH; i < firH+R; i++) 
            for (int j = firW; j < firW+C; j++) 
                if (!bck[i-firH][j-firW])
                    board[i][j] = true;
    }

    // 회전 90도
    isContinue = true;
    for (bckW = R-1; bckW >= 0; bckW--) 
        if (!bck[bckW][0])
            break;
    firH = hn; firW = wn-(R-1-bckW);
    for (int i = firH; i < firH+C; i++) {
        for (int j = firW; j < firW+R; j++) {
            if ((i < 0) || (i >= H) || (j < 0) || (j >= W)) {
                isContinue = false;
                break;
            }
            else {
                if (!bck[R-1-(j-firW)][i-firH] && !board[i][j]) {
                    isContinue = false;
                    break;
                }
            }
        }
        if (!isContinue)
            break;
    }
    if (isContinue) {
        for (int i = firH; i < firH+C; i++) 
            for (int j = firW; j < firW+R; j++) 
                if (!bck[R-1-(j-firW)][i-firH])
                    board[i][j] = false;
        ret += play(board, blkNum-bckSize);
        for (int i = firH; i < firH+C; i++) 
            for (int j = firW; j < firW+R; j++) 
                if (!bck[R-1-(j-firW)][i-firH])
                    board[i][j] = true;
    }
     
    // 회전 180도
    isContinue = true;
    for (bckW = 0; bckW < C; bckW) 
        if (!bck[0][bckW])
            break;
    firH = hn; firW = wn-bckW;
    for (int i = firH; i < firH+R; i++) {
        for (int j = firW; j < firW+C; j++) {
            if ((i < 0) || (i >= H) || (j < 0) || (j >= W)) {
                isContinue = false;
                break;
            }
            else {
                if (!bck[i-firH][j-firW] && !board[i][j]) {
                    isContinue = false;
                    break;
                }
            }
        }
        if (!isContinue)
            break;
    }
    if (isContinue) {
        for (int i = firH; i < firH+R; i++) 
            for (int j = firW; j < firW+C; j++) 
                if (!bck[i-firH][j-firW])
                    board[i][j] = false;
        ret += play(board, blkNum-bckSize);
        for (int i = firH; i < firH+R; i++) 
            for (int j = firW; j < firW+C; j++) 
                if (!bck[i-firH][j-firW])
                    board[i][j] = true;
    }
    
    // 회전 270도
    isContinue = true;
    for (bckW = 0; bckW < C; bckW) 
        if (!bck[0][bckW])
            break;
    firH = hn; firW = wn-bckW;
    for (int i = firH; i < firH+R; i++) {
        for (int j = firW; j < firW+C; j++) {
            if ((i < 0) || (i >= H) || (j < 0) || (j >= W)) {
                isContinue = false;
                break;
            }
            else {
                if (!bck[i-firH][j-firW] && !board[i][j]) {
                    isContinue = false;
                    break;
                }
            }
        }
        if (!isContinue)
            break;
    }
    if (isContinue) {
        for (int i = firH; i < firH+R; i++) 
            for (int j = firW; j < firW+C; j++) 
                if (!bck[i-firH][j-firW])
                    board[i][j] = false;
        ret += play(board, blkNum-bckSize);
        for (int i = firH; i < firH+R; i++) 
            for (int j = firW; j < firW+C; j++) 
                if (!bck[i-firH][j-firW])
                    board[i][j] = true;
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
                    bck[rn][cn] = false;
                    bckSize++;
                }
        }
        printf("%d\n", play(board, blankNum));
    }
}
