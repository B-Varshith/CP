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

vector<vector<int>> adj;
vi cnt;
void *dp;

void fillDp(int node,int par){
    cnt[node] = 1;
    for(int child : adj[node]){
        if (child != par){
            fillDp(child,node);
            cnt[node] += cnt[child];
        }
    }
}

void dfs(int node,int par){
    vi child;
    for(int son : adj[node]){
        if (son != par){
            child.push_back(son);
            dfs(son,node);
        }
    }

    if (child.empty()) return;
    if (child.size() == 1){
        dp[node] = cnt[child[0]] - 1;
        return;
    }

    int node1 = child[0],node2 = child[1];
    dp[node] = max(dp[node],dp[node2]+cnt[node1]-1);
    dp[node] = max(dp[node],dp[node1]+cnt[node2]-1);
}

void solve(){
    int n;cin >> n;
    adj.resize(n+1);
    for (int i = 0; i < n-1; ++i) {
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cnt.resize(n+1);
    fillDp(1,0);
    dp.resize(n+1);
    dfs(1,0);

    cout << dp[1] << endl;

    cnt.clear();
    adj.clear();
    dp.clear();
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
