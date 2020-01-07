#include <cstdio>

int N;
int level, fin;
int cnt[10] = {0,};
int save[10][10] = {0,};

int make10 (int time) {
    int x = 1;
    for (int i = 0; i < time; i++) 
        x *= 10;
    return x;
}

void makeSave (int idx)
{
    for (int i = 0; i < 10; i++) {
        save[idx][i] = 0;
        save[idx][i] += save[idx-1][i];  
    }

    for (int i = 1; i < 10; i++) {
        save[idx][i] += make10(idx);
        for (int j = 0; j < 10; j++) {
            save[idx][j] += save[idx-1][j];
        }
    }

    return;
}

void count (void)
{
    printf("* final count\n");
    int n;
    for (int i = level; i >= 0; i--) {
        n = N;
        for (int j = 0; j < i; j++) {
            n = n / 10;
        }
        n = n % 10;
        printf("i: %d, n = %d\n", i, n);
        int fk = make10(i) * n - 1;
        printf("0 ~ %d\n", fk);

        if (i == 0) {
            for (int j = 0; j <= n; j++) 
                cnt[j] += 1;
        }
        else {
            for (int j = 0; j < 10; j++) 
                cnt[j] += save[i-1][j];
            for (int j = 1; j < n; j++) {
                cnt[j] += make10(i);
                for (int k = 0; k < 10; k++) 
                    cnt[k] += save[i-1][k];
            }
        }

        printf("- cnt     : ");
        for (int i = 0; i < 10; i++) {
            printf("%d ", cnt[i]);
        }
        printf("\n");
    }

}

void saveSet (int curLev) 
{
    printf("\ncount(%d)\n", curLev);
    if (curLev != level) {
        if (save[curLev][0] == 0) {
            printf("makeSave(%d)\n", curLev);
            makeSave(curLev);
        }

        printf("- save[%d] : ", curLev);
        for (int i = 0; i < 10; i++) {
            printf("%d ", save[curLev][i]);
        }
        printf("\n");

        saveSet(curLev+1);
    }
    else {
        count();
    }
}

int main(void)
{
    scanf("%d", &N);
    printf("input: %d\n", N);

    int tmp = N;
    for(int i = 0; i < 9; i++) {
        if (tmp < 10) {
            level = i;
            fin = tmp;
            printf("level: %d, fin: %d\n", level, fin);
            break;
        }
        tmp = tmp / 10;
    }

    for (int i = 0; i < 10; i++) {
        save[0][i] = 1;
    }
    saveSet(0);
    cnt[0] -= 1;
    for (int i = 0; i < 10; i++) {
        printf("%d ", cnt[i]);
    }
    printf("\n");

    return 0;
}
