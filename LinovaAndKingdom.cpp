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

void solve(){
    int n,k;cin >> n >> k;
    unordered_map<int,vi> adj;
    for (int i = 0; i < n-1; ++i) {
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> depth(n+1);
    vector<bool> vis(n+1,false);
    queue<pair<int,int>> q;
    q.emplace(1,1);
    depth[1] = 1;
    vis[1] = true;
    while (!q.empty()){
        auto [node,lev] = q.front();
        q.pop();
        depth[node] = lev;
        for(int child : adj[node]){
            if (!vis[child]){
                q.emplace(child,lev+1);
                vis[child] = true;
            }
        }
    }
    sort(all(depth),greater<>());

    for(int i : depth){
        cout << i << " ";
    }
    cout << endl;
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += depth[i]-1;
    }
    cout << sum << endl;
}

int32_t main() {
    fast_io();
    setIO();
    int t = 1;
    while (t--) solve();
}