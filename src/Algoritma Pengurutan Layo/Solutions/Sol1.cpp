// Solusi fenwick tree + ordered_set C++

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

typedef long long ll;

/*               .___                 __                 __           .__
  ____  ____   __| _/____     _______/  |______ ________/  |_  ______ |  |__   ___________   ____
_/ ___\/  _ \ / __ |/ __ \   /  ___/\   __\__  \\_  __ \   __\/  ___/ |  |  \_/ __ \_  __ \_/ __ \
\  \__(  <_> ) /_/ \  ___/   \___ \  |  |  / __ \|  | \/|  |  \___ \  |   Y  \  ___/|  | \/\  ___/
 \___  >____/\____ |\___  > /____  > |__| (____  /__|   |__| /____  > |___|  /\___  >__|    \___  >
     \/           \/    \/       \/            \/                 \/       \/     \/            \/
*/

struct bit
{
    int n;
    vector<ordered_set> lesgo;
    void resize(int _n)
    {
        n = _n;
        lesgo = vector<ordered_set>(n + 1);
    }
    void update(int pos, int val, int sign)
    {
        for (int i = pos; i <= n; i += i & (-i))
        {
            if (sign == -1)
            {
                lesgo[i].erase(val);
            }
            if (sign == 1)
            {
                lesgo[i].insert(val);
            }
        }
    }
    int query_smaller(int pos, int val)
    {
        int ans = 0;
        for (int i = pos; i; i -= i & (-i))
        {
            ans += lesgo[i].order_of_key(val);
        }
        return ans;
    }
    int query_greater(int pos, int val)
    {

        int ans = 0;
        for (int i = pos; i; i -= i & (-i))
        {
            int sz = lesgo[i].size();
            ans += sz - lesgo[i].order_of_key(val + 1);
        }
        return ans;
    }
    int query_smaller(int st, int dr, int val)
    {
        return query_smaller(dr, val) - query_smaller(st - 1, val);
    }
    int query_greater(int st, int dr, int val)
    {
        return query_greater(dr, val) - query_greater(st - 1, val);
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
    bit lesgo;
    lesgo.resize(n);
    for (int i = 1; i <= n; ++i)
    {
        lesgo.update(i, a[i], 1);
    }

    ll inv = 0;

    for (int i = 1; i <= n; ++i)
    {
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
            lesgo.update(x, a[x], -1);
            lesgo.update(y, a[y], -1);
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
            lesgo.update(x, a[x], 1);
            lesgo.update(y, a[y], 1);
        }
        cout << sum + sum - inv << '\n';
    }
}