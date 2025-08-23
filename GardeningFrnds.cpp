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

int n,k,c;
unordered_map<int,vi> adj;
vi distFromRoot,distFromFarest,level;

void dfs2(int node,int par,int dist){
    for(int child : adj[node]){
        if (child != par){
            distFromFarest[child] = dist+1;
            dfs2(child,node,dist+1);
        }
    }
}
void dfs1(int node,int par,int dist){
    for(int child : adj[node]){
        if (child != par){
            distFromRoot[child] = dist+1;
            dfs1(child,node,dist+1);
        }
    }
}

void computeLevel(){
    vector<bool> vis(n+1);
    queue<pair<int,int>> q;
    q.emplace(1,0);
    while (!q.empty()){
        auto node = q.front();
        q.pop();
        if (!vis[node.first]){
            int lev = node.second;
            for(int child : adj[node.first]){
                if (!vis[child])
                q.emplace(child,lev+1);
            }
            level[node.first] = lev;
            vis[node.first] = true;
        }
    }
}

void solve(){
    cin >> n >> k >> c;
    for (int i = 0; i < n-1; ++i) {
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    distFromRoot.assign(n+1,0);
    distFromFarest.assign(n+1,0);
    level.assign(n+1,0);

    dfs1(1,0,0);
    int nodeFarest = -1;
    int maxi = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        if (distFromRoot[i] > maxi){
            nodeFarest = i;
            maxi = distFromRoot[i];
        }
    }
    dfs2(nodeFarest,0,0);
    computeLevel();

    int ans = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans,distFromFarest[i]*k-level[i]*c);
    }
    cout << ans << endl;
    adj.clear();
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