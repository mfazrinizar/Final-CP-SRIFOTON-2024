#include <cstdio>
#include <cstring>
 
typedef long long int64;
static const int MAXN = 52;
static const int LOGA = 56;
 
static int k, n;
static int64 a[MAXN], s[MAXN];
 
static bool feas[MAXN][MAXN];
 
inline bool dp_check(int64 targ, int64 mask)
{
    memset(feas, false, sizeof feas);
    feas[0][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j)
            if (((s[i] - s[j]) & mask & targ) == targ) {
                for (int k = 0; k < MAXN - 1; ++k)
                    if (feas[j][k]) feas[i][k + 1] = true;
            }
    }
    return feas[n][k];
}
 
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    s[0] = 0;
    for (int i = 0; i < n; ++i) s[i + 1] = s[i] + a[i];
 
    int64 ans = 0;
    for (int i = LOGA - 1; i >= 0; --i) {
        if (dp_check(ans | (1LL << i), ~((1LL << i) - 1))) ans |= (1LL << i);
    }
    printf("%lld\n", ans);
 
    return 0;
}