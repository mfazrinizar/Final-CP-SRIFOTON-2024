#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rnd(228);
 
const int N = 1e5 + 1;
 
vector <int> g[N];
 
vector <int> leafs;
 
void dfs(int v, int pr)
{
    int deg = 0;
    for (int to : g[v])
    {
        if (to != pr)
        {
            deg++;
            dfs(to, v);
        }
    }
    if (deg == 0)
    {
        leafs.push_back(v);
    }
}
 
int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int root = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if ((int) g[i].size() > 2)
        {
            cnt++;
            root = i;
        }
    }
    if (cnt > 1)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
        dfs(root, -1);
        cout << (int) leafs.size() << '\n';
        for (int i = 0; i < (int) leafs.size(); i++)
        {
            cout << root + 1 << ' ' << leafs[i] + 1 << '\n';
        }
    }
}