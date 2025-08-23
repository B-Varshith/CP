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

unordered_map<int,vi> adj;
int dp[200001][2];

void dfs(int src, int par) {
    vector<int> children;
    dp[src][0] = dp[src][1] = 0;

    for (int child : adj[src]) {
        if (child != par) {
            children.push_back(child);
            dfs(child, src);
        }
    }
    if (children.empty()) return;

    vector<int> prefix, suffix;
    for (int child : children) {
        prefix.push_back(max(dp[child][0], dp[child][1]));
        suffix.push_back(max(dp[child][0], dp[child][1]));
    }

    for (int i = 1; i < (int)prefix.size(); ++i) prefix[i] += prefix[i-1];
    for (int i = (int)suffix.size()-2; i >= 0; --i) suffix[i] += suffix[i+1];

    dp[src][0] = suffix[0];
    for (int i = 0; i < (int)children.size(); ++i) {
        int left = (i == 0) ? 0 : prefix[i-1];
        int right = (i == (int)children.size()-1) ? 0 : suffix[i+1];
        dp[src][1] = max(dp[src][1], 1 + left + right + dp[children[i]][0]);
    }
}

void solve(){
    int n;cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cout << max(dp[1][0],dp[1][1]) << endl;
}

int32_t main() {
    setIO();
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
