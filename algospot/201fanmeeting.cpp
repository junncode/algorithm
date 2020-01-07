#include <cstdio>

#define MAXSIZE 200000

int memNum, fanNum;
bool mem[MAXSIZE];
bool fan[MAXSIZE];

int check (void)
{
    int chkCnt = fanNum - memNum + 1;
    if (chkCnt <= 0)
        return 0;
    
    int ret = 0;
    for (int chk = 0; chk < chkCnt; chk++) {
        bool count = true;
        for (int i = 0; i < memNum; i++) {
            if (!(mem[i] || fan[i+chk])) {
                count = false;
                break;
            }
        }
        if (count)
            ret++;
    }

    return ret;
}

int main (void)
{
    int C;
    scanf("%d\n", &C);
    for (int tc = 0; tc < C; tc++) {
        int fin = 0;
        char tmp;
        memNum = 0;
        fanNum = 0;
        while (fin < 2) {
            scanf("%c", &tmp);
            
            if (tmp == '\n') {
                fin++;
                continue;
            }

            if (fin == 0) { 
                if (tmp == 'F')
                    mem[memNum++] = true;
                else
                    mem[memNum++] = false;
            }
            else if (fin == 1) {
                if (tmp == 'F')
                    fan[fanNum++] = true;
                else
                    fan[fanNum++] = false;
            }
        }

        printf("%d\n", check());
    }
}
