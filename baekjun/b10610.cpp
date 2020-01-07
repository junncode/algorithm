#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main (void)
{
    char n[100005];
    scanf("%s", n);
    bool isNoZero = true;
    int sum = 0, size;
    size = strlen(n);
    for (int i = 0; i < size; i++) {
        if (n[i] == '0') 
            isNoZero = false;
        sum += (int)(n[i] - '0');
    }
    if (isNoZero || ((sum % 3) != 0)) {
        printf("-1\n");
    }
    else {
        sort(n, n+size);
        for (int i = size-1; i >= 0; i--) 
            printf("%c", n[i]);
        printf("\n");
    }
    return 0;
}
