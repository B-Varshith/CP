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

void dfs(int node,int par,unordered_map<int,vi> &adj,vector<int> &a){
    for(int child : adj[node]){
        if (child == par) continue;
        dfs(child,node,adj,a);
    }
    for(int child : adj[node]){
        if (child != par){
            a[node] += (a[child] + 1);
        }
    }
}

void solve(){
    int n;cin >> n;
    vi a(n-1);
    rep(i,0,n-1) cin >> a[i];
    unordered_map<int,vi> adj;
    for (int i = 0; i < n-1; ++i) {
        adj[i+2].push_back(a[i]);
        adj[a[i]].push_back(i+2);
    }
    vector<int> v(n+1,0);
    dfs(1,-1,adj,v);
    for (int i = 1; i <= n; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    setIO();
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
