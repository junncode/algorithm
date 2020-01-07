#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int find(int n1, int n2)
{
    for (int i = 1; i <= 3; i++) {
        if ((i != n1) && (i != n2))
            return i;
    }
    return 0;
}

int hanoi(int level)
{
    if (level == 1) {
        return 1;
    }
    else
        return (2 * hanoi(level-1) + 1);
    
}

void printH(int level, int from, int to) {
    if (level == 0) {
        return;
    }
    printH(level-1, from, find(from, to));
    printf("%d %d\n", from, to);
    printH(level-1, find(from, to), to);
    return;
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);

    string s = to_string(powl(2, N));
    //cout << "1:  " << s << endl;
    int idx = s.find('.');
    //printf("idx: %d\n", idx);
    s = s.substr(0, idx);
    //cout << "2:  " << s << endl;
    //printf("s.length() - 1: %lu\n", s.length() - 1);
    s[s.length() - 1] -= 1;
    cout << s << endl;

    if (N <= 20) {
        printH(N, 1, 3);
    }
    return 0;
}
