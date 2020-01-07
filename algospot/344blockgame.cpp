#include <cstdio>

const int di3[12] = {1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1};
const int dj3[12] = {0, 0, 1, 1, 1, 0, 1, 1, 0, 1, -1, 0};
int cnt;

bool play(bool board[5][5])
{
    bool ret = true;
    bool isPut = false;
    /*
    printf("cnt: %d\n", ++cnt);
    printf("< before >\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j])
                printf("_ ");
            else
                printf("ㅁ");
        }
        printf("\n");
    }
    printf("\n");
*/
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j]) {
                int nextI, nextJ, nextI3, nextJ3;
                for (int k = 0; k < 6; k++) {
                    nextI = i + di3[k*2];
                    nextJ = j + dj3[k*2];
                    nextI3 = i + di3[k*2+1];
                    nextJ3 = j + dj3[k*2+1];
                    if ((nextI < 5) && (nextI3 < 5) && (nextJ < 5) && (nextJ >= 0) && (nextJ3 < 5) && (nextJ3 >= 0)) {
                        if (board[nextI][nextJ] && board[nextI3][nextJ3]) {
          //                  printf("(%d, %d)-%d put\n", i, j, k);
                            isPut = true;
                            board[i][j] = board[nextI][nextJ] = board[nextI3][nextJ3] = false;
                            ret = ret && play(board);
                            if (!ret)
                                break;
                            board[i][j] = board[nextI][nextJ] = board[nextI3][nextJ3] = true;
                        }
                    }
                }
            }
                            if (!ret)
                                break;
        }
                            if (!ret)
                                break;
    }
    /*
    printf("\n");
    printf("< after >\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j])
                printf("_ ");
            else
                printf("ㅁ");
        }
        printf("\n");
    }*/

    if (!isPut) {
        //printf("it can't put!\n");
        return false;
    }
    return !ret;
}

int main (void)
{
    int C;
    scanf("%d", &C);
    bool board[5][5];
    for (int tc = 0; tc < C; tc++) {
        char tmp[6];
        for (int i = 0; i < 5; i++) {
            scanf("%s", tmp);
            for (int j = 0; j < 5; j++) {
                if (tmp[j] == '.')
                    board[i][j] = true;
                else
                    board[i][j] = false;
            }
        }

        cnt = 0;
        if (play(board))
            printf("WINNING\n");
        else
            printf("LOSING\n");
    }
}
