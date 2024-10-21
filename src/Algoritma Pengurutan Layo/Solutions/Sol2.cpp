// SQRT Decomposition

#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int random(int st, int dr)
{
    uniform_int_distribution<int> dist(st, dr);
    return dist(rng);
}

typedef long long ll;

/*               .___                 __                 __           .__
  ____  ____   __| _/____     _______/  |______ ________/  |_  ______ |  |__   ___________   ____
_/ ___\/  _ \ / __ |/ __ \   /  ___/\   __\__  \\_  __ \   __\/  ___/ |  |  \_/ __ \_  __ \_/ __ \
\  \__(  <_> ) /_/ \  ___/   \___ \  |  |  / __ \|  | \/|  |  \___ \  |   Y  \  ___/|  | \/\  ___/
 \___  >____/\____ |\___  > /____  > |__| (____  /__|   |__| /____  > |___|  /\___  >__|    \___  >
     \/           \/    \/       \/            \/                 \/       \/     \/            \/
*/

struct decomp
{
    vector<int> a;
    vector<pair<int, int>> buckets;
    vector<int> sp;
    vector<int> spbucket;
    vector<int> wh;
    const int sz = 400;
    void resize(int n)
    {
        a = vector<int>(n + 1);
        sp = vector<int>(n + 1);
        wh = vector<int>(n + 1);
        for (int i = 1; i <= n; i += sz)
        {
            int st = i;
            int dr = min(n, st + sz - 1);
            for (int j = st; j <= dr; ++j)
            {
                wh[j] = (int)buckets.size();
            }
            buckets.push_back({st, dr});
            spbucket.push_back(0);
        }
    }
    void update(int pos, int x)
    {
        a[pos] += x;
        int qui = wh[pos];
        sp[buckets[qui].first] = a[buckets[qui].first];
        for (int i = buckets[qui].first + 1; i <= buckets[qui].second; ++i)
        {
            sp[i] = sp[i - 1] + a[i];
        }
        spbucket[0] = sp[buckets[0].second];
        for (int i = 1; i < (int)buckets.size(); ++i)
        {
            spbucket[i] = spbucket[i - 1] + sp[buckets[i].second];
        }
    }
    int query(int pos)
    {
        int qui = wh[pos];
        int ans = sp[pos];
        if (qui)
        {
            ans += spbucket[qui - 1];
        }
        return ans;
    }
};

struct geralt
{
    vector<int> a;
    vector<decomp> lesgo;
    vector<pair<int, int>> buckets;
    vector<int> wh;
    const int sz = 3000;
    void resize(int n)
    {
        a = vector<int>(n + 1);
        wh = vector<int>(n + 1);
        for (int i = 1; i <= n; i += sz)
        {
            int st = i;
            int dr = min(n, st + sz - 1);
            for (int j = st; j <= dr; ++j)
            {
                wh[j] = (int)buckets.size();
            }
            buckets.push_back({st, dr});
            lesgo.push_back({});
            lesgo.back().resize(n);
        }
    }
    void update(int pos, int val)
    {
        int qui = wh[pos];
        if (a[pos] != 0)
        {
            lesgo[qui].update(a[pos], -1);
        }
        a[pos] = val;
        lesgo[qui].update(a[pos], 1);
    }
    int query_brute(int st, int dr, int val)
    {
        int ans = 0;
        for (int i = st; i <= dr; ++i)
        {
            if (a[i] <= val)
            {
                ans++;
            }
        }
        return ans;
    }
    int query_smaller(int st, int dr, int val) // number of values <= val in st...dr
    {
        if (wh[st] == wh[dr])
        {
            return query_brute(st, dr, val);
        }
        int qui1 = wh[st], qui2 = wh[dr];
        int ans = query_brute(st, buckets[qui1].second, val) + query_brute(buckets[qui2].first, dr, val);
        qui1++;
        qui2--;
        for (int i = qui1; i <= qui2; ++i)
        {
            ans += lesgo[i].query(val);
        }
        return ans;
    }
    int query_greater(int st, int dr, int val) // number of values > val in st...dr
    {
        return (dr - st + 1) - query_smaller(st, dr, val);
    }
};

int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    geralt lesgo;
    lesgo.resize(n);

    ll inv = 0;

    for (int i = 1; i <= n; ++i)
    {
        lesgo.update(i, a[i]);
        inv += lesgo.query_greater(1, i, a[i]);
    }

    ll sum = 0;

    for (int i = 1; i <= n; ++i)
    {
        sum += max(a[i] - i, 0);
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (x != y)
        {
            sum -= max(a[x] - x, 0);
            sum -= max(a[y] - y, 0);
            if (x + 1 <= y - 1)
            {
                int lesgo1 = lesgo.query_smaller(x + 1, y - 1, a[x]);
                int lesgo2 = lesgo.query_greater(x + 1, y - 1, a[y]);
                inv += 2 * (y - x - 1 - lesgo1 - lesgo2);
            }

            if (a[x] > a[y])
            {
                inv--;
            }
            else
            {
                inv++;
            }

            swap(a[x], a[y]);
            sum += max(a[x] - x, 0);
            sum += max(a[y] - y, 0);
            lesgo.update(x, a[x]);
            lesgo.update(y, a[y]);
        }
        cout << sum + sum - inv << '\n';
    }
}