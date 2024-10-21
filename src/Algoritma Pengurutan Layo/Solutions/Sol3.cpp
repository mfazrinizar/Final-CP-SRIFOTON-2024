// Divide & Conquer

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>
#define i4 tuple<int, int, int, int>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x, start, end) for (int x = (start) - ((start) > (end)); x != (end) - ((start) > (end)); ((start) < (end) ? x++ : x--))
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

/*               .___                 __                 __           .__
  ____  ____   __| _/____     _______/  |______ ________/  |_  ______ |  |__   ___________   ____
_/ ___\/  _ \ / __ |/ __ \   /  ___/\   __\__  \\_  __ \   __\/  ___/ |  |  \_/ __ \_  __ \_/ __ \
\  \__(  <_> ) /_/ \  ___/   \___ \  |  |  / __ \|  | \/|  |  \___ \  |   Y  \  ___/|  | \/\  ___/
 \___  >____/\____ |\___  > /____  > |__| (____  /__|   |__| /____  > |___|  /\___  >__|    \___  >
     \/           \/    \/       \/            \/                 \/       \/     \/            \/
*/

struct FEN
{ // we want to count the reverse
    int arr[500005];

    void update(int i, int k)
    {
        i = 500005 - i;

        while (i < 500005)
        {
            arr[i] += k;
            i += i & -i;
        }
    }

    int query(int i)
    {
        i = 500005 - i;

        int res = 0;
        while (i)
        {
            res += arr[i];
            i -= i & -i;
        }
        return res;
    }
} fen;

int n, q;
int arr[500005];
long long ans[50005];

void dnc(int l, int r, vector<i4> upd, vector<i4> que)
{
    vector<i4> updl, updr;
    vector<i4> quel, quer;

    int m = l + r >> 1;

    for (auto [a, b, c, d] : upd)
    {
        if (c <= m)
            updl.pub({a, b, c, d});
        else
            updr.pub({a, b, c, d});
    }

    for (auto [a, b, c, d] : que)
    {
        if (c <= m)
            quel.pub({a, b, c, d});
        else
            quer.pub({a, b, c, d});
    }

    int i = 0;
    for (auto it : quer)
    {
        while (i < sz(updl) && get<0>(updl[i]) < get<0>(it))
        {
            fen.update(get<1>(updl[i]), get<3>(updl[i]));
            i++;
        }

        ans[get<2>(it)] += fen.query(get<1>(it)) * get<3>(it);
    }
    while (i)
    {
        i--;
        fen.update(get<1>(updl[i]), -get<3>(updl[i]));
    }

    if (l != m)
        dnc(l, m, updl, quel);
    if (m + 1 != r)
        dnc(m + 1, r, updr, quer);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin.exceptions(ios::badbit | ios::failbit);

    cin >> n >> q;
    rep(x, 1, n + 1) cin >> arr[x];

    vector<i4> upd, que;

    rep(x, 1, n + 1) upd.pub({x, arr[x], -1, 1});
    rep(x, 1, n + 1) que.pub({x, arr[x], 0, -1});
    rep(x, 1, n + 1) ans[0] += abs(x - arr[x]);

    rep(x, 1, q + 1)
    {
        int a, b;
        cin >> a >> b;

        if (a == b)
            continue;
        if (arr[a] < arr[b])
            ans[x]--;
        else
            ans[x]++;

        upd.pub({a, arr[a], x - 1, -1});
        upd.pub({b, arr[b], x - 1, -1});
        ans[x] -= abs(a - arr[a]) + abs(b - arr[b]);

        swap(arr[a], arr[b]);

        upd.pub({a, arr[a], x, 1});
        upd.pub({b, arr[b], x, 1});
        ans[x] += abs(a - arr[a]) + abs(b - arr[b]);

        que.pub({b, arr[b], x, -2});
        que.pub({b, arr[a], x, 2});
        que.pub({a, arr[b], x, 2});
        que.pub({a, arr[a], x, -2});
    }

    sort(all(upd)), sort(all(que));

    dnc(-1, q, upd, que);

    rep(x, 1, q + 1) ans[x] += ans[x - 1];
    rep(x, 1, q + 1) cout << ans[x] << endl;
    cout << endl;
}