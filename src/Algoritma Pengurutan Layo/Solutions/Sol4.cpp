// Clock & Tree

#include <bits/stdc++.h>
#define rg register
#define file(x)                   \
    freopen(x ".in", "r", stdin); \
    freopen(x ".out", "w", stdout)

using namespace std;

const int maxn = 5e5 + 10;
const int maxQ = 5e4 + 10;

int n, Q;
int P[maxn];
int Color[maxn];
inline int judge(int x)
{
    if (P[x] > x)
        return 1;
    if (P[x] < x)
        return -1;
    return 0;
}

pair<int, int> Tran[maxQ];
long long Ans[maxQ];

int Clock;
struct Change
{
    int id, V, Time, opt, Type;
} Changelog[maxQ << 3];
int tot;
struct Question
{
    int id, V, Time, Qid, opt, Type;
} Ask[maxQ << 2];
int tnt;

auto cmp = [](auto x, auto y)
{ return x.id < y.id; };
namespace BIT
{
    int Tree[maxn];
    inline void clear()
    {
        for (rg int i = 1; i <= n; i += 1)
            Tree[i] = 0;
    }
    inline void add(int x, int V)
    {
        for (; x <= n; x += x & (-x))
            Tree[x] += V;
    }
    inline int Query(int x)
    {
        int re = 0;
        for (; x; x -= x & (-x))
            re += Tree[x];
        return re;
    }
}
inline void solve(int TL, int TR, int CL, int CR, int QL, int QR)
{
    if (CL > CR)
    {
        sort(Ask + QL, Ask + QR + 1, cmp);
        return;
    }
    if (QL > QR)
    {
        sort(Changelog + CL, Changelog + CR + 1, cmp);
        return;
    }
    int mid = (TL + TR) >> 1;
    int p1 = CL, p2 = QL;
    while (p1 <= CR && Changelog[p1].Time <= mid)
        p1 += 1;
    while (p2 <= QR && Ask[p2].Time <= mid)
        p2 += 1;
    solve(TL, mid, CL, p1 - 1, QL, p2 - 1);
    solve(mid + 1, TR, p1, CR, p2, QR);
    int p = CL;
    auto ins = [&](Change x, bool rev)
    {
        int V = x.V;
        if (rev)
            V = n - V + 1;
        BIT::add(V, x.opt ? 1 : -1);
    };
    auto del = [&](Change x, bool rev)
    {
        int V = x.V;
        if (rev)
            V = n - V + 1;
        BIT::add(V, x.opt ? -1 : 1);
    };
    auto query = [&](Question x, bool rev)
    {
        int V = x.V;
        if (rev)
            V = n - V + 1;
        return BIT::Query(V);
    };
    for (rg int i = p2; i <= QR; i += 1)
    {
        while (p < p1 && Changelog[p].id < Ask[i].id)
            if (Changelog[p].Type == 1)
                ins(Changelog[p++], true);
            else
                p += 1;
        Ans[Ask[i].Qid] +=
            ((Ask[i].opt ^ (Ask[i].Type == 1)) ? 1 : -1) * query(Ask[i], true);
    }
    for (rg int i = CL; i < p; i += 1)
        if (Changelog[i].Type == 1)
            del(Changelog[i], true);
    p = CL;
    for (rg int i = p2; i <= QR; i += 1)
    {
        while (p < p1 && Changelog[p].id < Ask[i].id)
            if (Changelog[p].Type != 1)
                ins(Changelog[p++], true);
            else
                p += 1;
        if (Ask[i].Type != 1)
            Ans[Ask[i].Qid] +=
                (Ask[i].opt ? -1 : 1) * query(Ask[i], true);
    }
    for (rg int i = CL; i < p; i += 1)
        if (Changelog[i].Type != 1)
            del(Changelog[i], true);
    p = p1 - 1;
    for (rg int i = QR; i >= p2; i -= 1)
    {
        while (p >= CL && Changelog[p].id > Ask[i].id)
            if (Changelog[p].Type != 1)
                ins(Changelog[p--], false);
            else
                p -= 1;
        Ans[Ask[i].Qid] +=
            ((Ask[i].opt ^ (Ask[i].Type == 1)) ? -1 : 1) * query(Ask[i], false);
    }
    for (rg int i = p + 1; i < p1; i += 1)
        if (Changelog[i].Type != 1)
            del(Changelog[i], false);
    p = p1 - 1;
    for (rg int i = QR; i >= p2; i -= 1)
    {
        while (p >= CL && Changelog[p].id > Ask[i].id)
            if (Changelog[p].Type == 1)
                ins(Changelog[p--], false);
            else
                p -= 1;
        if (Ask[i].Type == 1)
            Ans[Ask[i].Qid] +=
                (Ask[i].opt ? -1 : 1) * query(Ask[i], false);
    }
    for (rg int i = p + 1; i < p1; i += 1)
        if (Changelog[i].Type == 1)
            del(Changelog[i], false);
    inplace_merge(Changelog + CL, Changelog + p1, Changelog + CR + 1, cmp);
    inplace_merge(Ask + QL, Ask + p2, Ask + QR + 1, cmp);
}

int main()
{
    scanf("%d %d", &n, &Q);
    for (rg int i = 1; i <= n; i += 1)
        scanf("%d", P + i);
    static bool Mark[maxn];
    for (rg int i = 1; i <= n; i += 1)
        Mark[i] = false;
    for (rg int i = 1; i <= Q; i += 1)
    {
        auto &[x, y] = Tran[i];
        scanf("%d %d", &x, &y);
        if (x ^ y)
            Mark[x] = Mark[y] = true;
    }
    for (rg int i = 1; i <= n; i += 1)
        Color[i] = judge(i);
    {
        using namespace BIT;
        for (rg int i = n; i; i -= 1)
        {
            if (Color[i] == -1)
                add(P[i], 1);
            if (Color[i] == 1)
                Ans[1] += Query(P[i]);
        }
        clear();
        for (rg int i = n; i; i -= 1)
            if (Color[i] == 1)
            {
                Ans[1] -= Query(P[i]);
                add(P[i], 1);
            }
        clear();
        for (rg int i = n; i; i -= 1)
            if (Color[i] == -1)
            {
                Ans[1] -= Query(P[i]);
                add(P[i], 1);
            }
        clear();
    }
    static vector<pair<int, int>> Add[maxn], Del[maxn];
    for (rg int i = 1; i <= n; i += 1)
        Add[i].clear(), Del[i].clear();
    auto Insert = [&](int x, int Qid)
    {
        Color[x] = judge(x);
        if (Color[x] == 0)
            return;
        if (Qid > 0)
        {
            Ask[++tnt] = (Question){x, P[x], ++Clock, Qid, 1, Color[x]};
            Add[x].emplace_back(P[x], Qid);
        }
        Changelog[++tot] = (Change){x, P[x], ++Clock, 1, Color[x]};
    };
    auto Delete = [&](int x, int Qid)
    {
        if (Color[x] == 0)
            return;
        Changelog[++tot] = (Change){x, P[x], ++Clock, 0, Color[x]};
        if (Qid > 0)
        {
            Ask[++tnt] = (Question){x, P[x], ++Clock, Qid, 0, Color[x]};
            Del[x].emplace_back(P[x], Qid);
        }
    };
    for (rg int i = 1; i <= n; i += 1)
        if (Mark[i])
            Insert(i, 0);
    for (rg int i = 1; i <= Q; i += 1)
    {
        auto [x, y] = Tran[i];
        if (x == y)
            continue;
        Delete(x, i);
        Delete(y, i);
        swap(P[x], P[y]);
        Insert(x, i);
        Insert(y, i);
    }
    {
        using namespace BIT;
        for (rg int i = n; i; i -= 1)
            if (Mark[i])
            {
                for (auto [V, Qid] : Add[i])
                    if (V > i)
                        Ans[Qid] += Query(V);
                for (auto [V, Qid] : Del[i])
                    if (V > i)
                        Ans[Qid] -= Query(V);
            }
            else
            {
                if (Color[i] == -1)
                    add(P[i], 1);
                else if (Color[i] == 1)
                    add(P[i], -1);
            }
        clear();
        for (rg int i = 1; i <= n; i += 1)
            if (Mark[i])
            {
                for (auto [V, Qid] : Add[i])
                    if (V < i)
                        Ans[Qid] += Query(n - V + 1);
                for (auto [V, Qid] : Del[i])
                    if (V < i)
                        Ans[Qid] -= Query(n - V + 1);
            }
            else
            {
                if (Color[i] == 1)
                    add(n - P[i] + 1, 1);
                else if (Color[i] == -1)
                    add(n - P[i] + 1, -1);
            }
        clear();
        for (rg int i = n; i; i -= 1)
            if (Mark[i])
            {
                for (auto [V, Qid] : Add[i])
                    if (V < i)
                        Ans[Qid] += Query(V);
                for (auto [V, Qid] : Del[i])
                    if (V < i)
                        Ans[Qid] -= Query(V);
            }
            else if (Color[i] == -1)
                add(P[i], -1);
        clear();
        for (rg int i = 1; i <= n; i += 1)
            if (Mark[i])
            {
                for (auto [V, Qid] : Add[i])
                    if (V > i)
                        Ans[Qid] += Query(n - V + 1);
                for (auto [V, Qid] : Del[i])
                    if (V > i)
                        Ans[Qid] -= Query(n - V + 1);
            }
            else if (Color[i] == 1)
                add(n - P[i] + 1, -1);
        clear();
    }
    solve(1, Clock, 1, tot, 1, tnt);
    for (rg int i = 1; i <= Q; i += 1)
        Ans[i] += Ans[i - 1];
    for (rg int i = 1; i <= Q; i += 1)
        printf("%lld\n", Ans[i]);
    return 0;
}