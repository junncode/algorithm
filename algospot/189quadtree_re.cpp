#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

char str[1005];
int idx;

string makeRev (void) 
{
    idx++;
    if (str[idx] != 'x') {
        return string(1, str[idx]);
    }

    string upL = makeRev();
    string upR = makeRev();
    string doL = makeRev();
    string doR = makeRev();

    return string("x") + doL + doR + upL + upR;
}

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        scanf("%s", str);

        idx = -1;
        cout << makeRev() << endl;
    }
}
