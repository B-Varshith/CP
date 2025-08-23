#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int MOD = 998244353;

void setIO(){
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

vector<pair<int,int>> a;
vector<vector<int>> adj;
vector<int> dpL, dpR;

void dfs(int node, int par) {
    for (int child : adj[node]) {
        if (child == par) continue;
        dfs(child, node);
        dpL[node] += max(abs(a[node].first - a[child].first) + dpL[child],
                         abs(a[node].first - a[child].second) + dpR[child]);
        dpR[node] += max(abs(a[node].second - a[child].first) + dpL[child],
                         abs(a[node].second - a[child].second) + dpR[child]);
    }
}

void solve() {
    int n;
    cin >> n;
    a.resize(n + 1);
    adj.resize(n + 1);
    dpL.resize(n + 1);
    dpR.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    cout << max(dpL[1], dpR[1]) << endl;
    adj.clear();
    dpL.clear();
    dpR.clear();
    a.clear();
}


int32_t main() {
    setIO();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
