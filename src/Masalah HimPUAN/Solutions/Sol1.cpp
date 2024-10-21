#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
#define lb(x,y) lower_bound(all(x),y)-begin(x)
 
mt19937 rng;
 
vector<int> a;
vector<int> tree;
 
int rec(int L, int R, int h = 0) {
    if (L > R) return 0;
    int l = L + sz(tree) / 2, r = R + sz(tree) / 2;
    int M = -1;
    while (l <= r) {
        if (l % 2 == 1) {
            if (tree[l] != -1 && (M == -1 || a[tree[l]] < a[M])) M = tree[l];
            l >>= 1;
            l++;
        } else {
            l >>= 1;
        }
        if (r % 2 == 0) {
            if (tree[r] != -1 && (M == -1 || a[tree[r]] < a[M])) M = tree[r];
            r >>= 1;
            r--;
        } else {
            r >>= 1;
        }
    }
    return min(rec(L, M - 1, a[M]) + rec(M + 1, R, a[M]) + a[M] - h, R - L + 1);
}
 
void solve() {
    int N; cin >> N;
    a = vector<int>(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    int M = 1;
    while (M < N) M <<= 1;
    tree = vector<int>(M * 2, -1);
    for (int i = 0; i < N; i++) {
        tree[i + M] = i;
    }
    for (int i = M - 1; i > 0; i--) {
        if (tree[i * 2] != -1 && (tree[i * 2 + 1] == -1 || a[tree[i * 2]] < a[tree[i * 2 + 1]])) tree[i] = tree[i * 2];
        else tree[i] = tree[i * 2 + 1];
    }
    cout << rec(0, N - 1) << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
 
    solve();
 
    return 0;
}