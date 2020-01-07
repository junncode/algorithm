#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

char str[1005] = {0,};
int idx = -1;

string makeRev(void)
{
    idx++;
    if (str[idx] == 'b') {
        return string("b");
    }
    else if (str[idx] == 'w') {
        return string("w");
    }

    string upL = makeRev();
    string upR = makeRev();
    string loL = makeRev();
    string loR = makeRev();

    return string("x") + loL + loR + upL + upR;
}

int main(void)
{
    int C = 0;
    scanf("%d", &C);
    for (int testCnt = 0; testCnt < C; testCnt++) {
        scanf("%s", str);

        idx = -1;
        if (str[0] != 'x') {
            printf("%s\n", str);
        }
        else {
            cout << makeRev() << endl;
        }
    }

    return 0;
}
