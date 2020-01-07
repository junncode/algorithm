#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main (void)
{
    char A[52], B[52];
    scanf("%s %s", A, B);
    int ans = 50;
    for (int i = 0; i <= strlen(B) - strlen(A); i++) {
        int cur = 0;
        for (int j = 0; j < strlen(A); j++) 
            if (A[j] != B[j+i])
                cur++;
        ans = min(ans, cur);
    }
    printf("%d\n", ans);
}
