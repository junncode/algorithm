#include <cstdio>
#include <string.h>

int n, board[100][100], cashe[100][100];

int check (int cy, int cx)
{
    if (cy >= n || cx >= n) 
        return 0;
    if (cy == n-1 && cx == n-1) 
        return 1;

    int size = board[cy][cx];
    int& ret = cashe[cy][cx];
    if (ret != -1) 
        return ret;
    ret = (check(cy + size, cx) || (check(cy, cx + size)));
    return ret;
}

int main (void)
{
    int C;
    scanf("%d", &C);
    for (int tc = 0; tc < C; tc++) {
        scanf("%d", &n);
        for (int by = 0; by < n; by++) 
            for (int bx = 0; bx < n; bx++) 
                scanf("%d", &board[by][bx]);
        memset(cashe, -1, sizeof(cashe));
        if (check(0, 0)) 
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
