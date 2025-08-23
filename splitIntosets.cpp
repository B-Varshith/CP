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

int f;

void dfs(int node,unordered_map<int,vi> &adj,vi &color){
    for(int child : adj[node]){
        if (color[child] == -1){
            color[child] = 1 - color[node];
            dfs(child,adj,color);
        }else if (color[node] == color[child]){
            f++;
            return;
        }
    }
}

void solve(){
    f = 0;
    int n;cin >> n;
    unordered_map<int,vi> adj;

    for (int i = 0; i < n; ++i) {
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (adj[u].size() >= 3 || adj[v].size() >= 3){
            f++;
        }
    }

    vi color(n+1,-1);
    for (int i = 1; i <= n; ++i) {
        if (color[i] == -1){
            color[i] = 0;
            dfs(i,adj,color);
        }
    }

    if (f > 0){
        cout << "No" << endl;
        return;
    }else{
        cout << "Yes" << endl;
    }
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
