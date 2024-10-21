#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <fstream>
#include <cassert>
using namespace std;

#define boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define sz(a) int((a).size())
#define rep(i, s, n) for (int i = s; i <= (n); ++i)
#define rev(i, n, s) for (int i = (n); i >= s; --i)
#define fore(x, a) for (auto &&x : a)
typedef long long ll;
const int mod = 1000000007;
const int N = 100005;

int a[9];
int t;
int b[16];
ll dp[8][16];
ll c[9][9];

ll go(int p, int x)
{
    if (p == -1)
        return 1;
    if (x == 0)
    {
        if (t - b[x] >= p + 1)
            return 1;
        return 0;
    }
    ll &res = dp[p][x];
    if (res >= 0)
        return res;
    res = 0;
    rep(i, 0, min(p + 1, t - b[x]))
    {
        res += c[p + 1][i] * go(p - i, x - 1);
    }
    return res;
}

char hex(int x)
{
    if (x >= 10)
        return 'a' + (x - 10);
    return 'a' + x;
}

ll g[9];

ll f(int x)
{
    ll res = 0;
    memset(b, 0, sizeof(b));
    rep(i, 1, 15)
    {
        memset(dp, -1, sizeof(dp));
        b[i]++;
        res += go(x - 1, 15);
        b[i]--;
    }
    return res;
}

int main()
{

    boost;
    ll k;
    cin >> k >> t;
    rep(i, 0, 8)
    {
        c[i][0] = 1;
        rep(j, 1, i)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    rep(i, 0, 8)
    {
        g[i] = f(i);
        if (i > 0)
            g[i] += g[i - 1];
    }
    ll lo = 1, hi = (1LL << 36) - 1;
    while (lo < hi)
    {
        ll mi = (lo + hi) / 2;
        ll p = mi + 1;
        int td = 0;
        rep(i, 0, 8)
        {
            a[i] = p % 16;
            p /= 16;
            td = i;
            if (p == 0)
            {
                break;
            }
        }
        ll tot = td > 0 ? g[td - 1] : 0;
        memset(b, 0, sizeof(b));
        rev(i, td, 0)
        {
            rep(j, (i == td) ? 1 : 0, a[i] - 1)
            {
                b[j]++;
                if (b[j] <= t)
                {
                    memset(dp, -1, sizeof(dp));
                    tot += go(i - 1, 15);
                }
                b[j]--;
            }
            b[a[i]]++;
            if (b[a[i]] > t)
                break;
        }
        if (tot >= k)
            hi = mi;
        else
            lo = mi + 1;
    }
    vector<int> ans;
    while (lo > 0)
    {
        ans.push_back(lo % 16);
        lo /= 16;
    }
    reverse(ans.begin(), ans.end());
    fore(x, ans)
    {
        cout << hex(x);
    }
    cout << endl;
}