#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> multiply (const vector<int>& a, const vector<int>& b)
{
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += a[i] * b[j];
    return c;
}

// karaAdd(a, b, k)  => a += b * 10^k
void karaAdd (vector<int>& a, const vector<int>& b, int k)
{
    a.resize(max(a.size(), b.size() + k));
    for (int i = 0; i < b.size(); i++)
        a[i+k] += b[i];
}

// karaSub(a, b)  => a -= b
void karaSub (vector<int>& a, const vector<int>& b)
{
    a.resize(max(a.size(), b.size()) + 1);
    for (int i = 0; i < b.size(); i++)
        a[i] -= b[i];
}

// karatsuba(M, F)  => M * F
vector<int> karatsuba (vector<int>& F, vector<int>& M)
{

    int fSize = F.size();
    int mSize = M.size();
    if (fSize < mSize)  // F가 M보다 짧은 경우 둘을 바꿈
        return karatsuba(M, F);

    if (fSize == 0 || mSize == 0)  // F나 M이 비어있다면 base case
        return vector<int>();

    if (fSize <= 50)
        return multiply(F, M);

    int half = fSize / 2;
    vector<int> f0(F.begin(), F.begin() + half);
    vector<int> f1(F.begin() + half, F.end());
    vector<int> m0(M.begin(), M.begin() + min(mSize, half));
    vector<int> m1(M.begin() + min(mSize, half), M.end());

    printf("f0[%lu]: ", f0.size());
    for (int i = 0; i < f0.size(); i++) {
        printf("%d", f0[i]);
    }
    printf("\n");
    printf("f1[%lu]: ", f1.size());
    for (int i = 0; i < f1.size(); i++) {
        printf("%d", f1[i]);
    }
    printf("\n");
    printf("m0[%lu]: ", m0.size());
    for (int i = 0; i < m0.size(); i++) {
        printf("%d", m0[i]);
    }
    printf("\n");
    printf("m1[%lu]: ", m1.size());
    for (int i = 0; i < m1.size(); i++) {
        printf("%d", m1[i]);
    }
    printf("\n");

    // z2 = f1 * m1
    // z0 = f0 * m0
    // z1 = (f0 + f1) * (m0 + m1) - z0 - z1
    // F x M = z0 + (z1 * 10^half) + (z2 * 10^(half*2) )
    vector<int> z2 = karatsuba(f1, m1);
    vector<int> z0 = karatsuba(f0, m0);

    karaAdd(f0, f1, 0);
    karaAdd(m0, m1, 0);
    vector<int> z1 = karatsuba(f0, m0);
    karaSub(z1, z0);
    karaSub(z1, z2);

    vector<int> ret;
    karaAdd(ret, z0, 0);
    karaAdd(ret, z1, half);
    karaAdd(ret, z2, half+half);
    return ret;
}

int main (void)
{
    int C;
    scanf("%d\n", &C);

    for (int tc = 0; tc < C; tc++) {
        string m, f;
        cin >> m;
        cin >> f;
        vector<int> mem;
        vector<int> fan;
        for (int i = 0; i < m.size(); i++) {
            if (m[i] == 'F')
                mem.push_back(0);
            else
                mem.push_back(1);
        }
        for (int i = 0; i < f.size(); i++) {
            if (f[i] == 'F')
                fan.push_back(0);
            else
                fan.push_back(1);
        }
        reverse(mem.begin(), mem.end());  // mem 벡터를 거꾸로 뒤집어줌.
/*
        printf("mem[%lu]: ", mem.size());
        for (int i = 0; i < mem.size(); i++) {
            printf("%d", mem[i]);
        }
        printf("\n");
        printf("fan[%lu]: ", fan.size());
        for (int i = 0; i < fan.size(); i++) {
            printf("%d", fan[i]);
        }
        printf("\n");
*/
        vector<int> count = karatsuba(mem, fan);
        int ans = 0;
        for (int i = mem.size() - 1; i < fan.size(); i++)
            if (count[i] == 0)
                ans++;
        printf("%d\n", ans);
    }

    return 0;
}
