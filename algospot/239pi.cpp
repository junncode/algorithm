#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF 987654321

char s[10005];
int num[10005], n, cashe[10005];
const int numSize[3] = {3, 4, 5};

void stoNum (void)  // '0' = 48
{
    for (int i = 0; i < n; i++) 
        num[i] = s[i] - 48;
}

bool is1(int idx, int size) {
    bool ret = true;
    for (int i = 0; i < size-1; i++) 
        if (num[idx+i] != num[idx+i+1]) {
            ret = false;
            break;
        }
    return ret;
}
bool is2(int idx, int size) {
    bool ret = true;
    for (int i = 0; i < size-1; i++) {
        if ((num[idx+i] - num[idx+i+1]) != 1) {
            ret = false;
            break;
        }
    }
    if (ret)
        return ret;
    ret = true;
    for (int i = 0; i < size-1; i++) {
        if ((num[idx+i] - num[idx+i+1]) != -1) {
            ret = false;
            break;
        }
    }
    return ret;
}
bool is4(int idx, int size) {
    bool ret = true;
    if (size == 3) {
        if (num[idx] != num[idx+2])
            ret = false;
    }
    else if (size == 4) {
        if (num[idx] != num[idx+2])
            ret = false;
        if (num[idx+1] != num[idx+3])
            ret = false;
    }
    else {
        if ((num[idx] != num[idx+2]) || (num[idx] != num[idx+4]))
            ret = false;
        if (num[idx+1] != num[idx+3])
            ret = false;
    }
    return ret;
}
bool is5(int idx, int size) {
    bool ret = true;
    int sub = num[idx] - num[idx+1];
    for (int i = 1; i < size-1; i++) {
        if ((num[idx+i] - num[idx+i+1]) != sub) {
            ret = false;
            break;
        }
    }
    return ret;
}

int whatL (int idx, int size) 
{
    if (is1(idx, size))
        return 1;
    else if (is2(idx, size))
        return 2;
    else if (is4(idx, size))
        return 4;
    else if (is5(idx, size))
        return 5;
    else
        return 10;
}

int level (int idx) 
{
    int rem = n - idx;
    if (rem <= 5) {
        if (rem <= 2) 
            return INF;
        else 
            return whatL(idx, rem);
    }

    int& ret = cashe[idx];
    if (ret != -1)
        return ret;
    
    int minL = INF;
    for (int i = 0; i < 3; i++) {
        int curSize = numSize[i];
        minL = min(minL, whatL(idx, curSize) + level(idx + curSize));
    }
    return ret = minL;
}

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        scanf("%s", s);
        n = strlen(s);
        stoNum();
        memset(cashe, -1, sizeof(cashe));
        printf("%d\n", level(0));
    }
    return 0;
}
