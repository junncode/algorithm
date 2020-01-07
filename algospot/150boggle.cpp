#include <stdio.h>
#include <string.h>

using namespace std;

int C = 0;  // C <= 50
char board[5][5] = {0,};  // 5 x 5 board
int N = 0;  // 1 <= N <= 10
char word[11];  // 1글자 이상 10글자 이하

const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool cashe[5][5][10];
int cnt = 0;

bool nextFind(int by, int bx, int wordIdx);
bool startFind(void);

int main(void)
{
    scanf("%d", &C);
    for (int testCnt = 0; testCnt < C; testCnt++) {
        for (int by = 0; by < 5; by++)  // 보드판 입력
            scanf("%s", board[by]);   

        scanf("%d", &N);  // 아는 단어 수 입력
        for (int knowWord = 0; knowWord < N; knowWord++) {
            scanf("%s", word);

            memset(cashe, true, sizeof(cashe));  // cashe 초기화
            if (startFind())
                printf("%s YES\n", word);
            else
                printf("%s NO\n", word);
        }
    }
    printf("count: %d\n", cnt);
}

bool nextFind(int by, int bx, int wordIdx) 
{
    cnt++;
    int nextWordIdx = wordIdx + 1;
    if (nextWordIdx >= strlen(word)) {
        return true;
    }

    int nextBy;
    int nextBx;
    for (int direc = 0; direc < 8; direc++) {
        nextBy = by + dy[direc];
        nextBx = bx + dx[direc];
        if ((nextBy >= 0) && (nextBy < 5) && (nextBx >= 0) && (nextBx < 5)) { // 범위 확인
            if (cashe[nextBy][nextBx][nextWordIdx] && (board[nextBy][nextBx] == word[nextWordIdx])) {
                if (nextFind(nextBy, nextBx, nextWordIdx))
                    return true;
            }
        }
    }
    cashe[by][bx][wordIdx] = false;
    printf("by: %d, bx: %d, wordIdx: %d  -> false\n", by, bx, wordIdx);
    return false;
}

bool startFind(void)
{
    for (int by = 0; by < 5; by++) {
        for (int bx = 0; bx < 5; bx++) {
            if (board[by][bx] == word[0]) 
                if (nextFind(by, bx, 0)) 
                    return true;
        }
    }
    return false;
}
