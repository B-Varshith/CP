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

void dfs(int node, int parent, int dist, unordered_map<int, vi> &adj, int &maxDist, int &farthestNode) {
    if (dist > maxDist) {
        maxDist = dist;
        farthestNode = node;
    }
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node, dist + 1, adj, maxDist, farthestNode);
        }
    }
}

int getMaxPathDist(unordered_map<int, vi> &adj) {
    if (adj.empty()) return 0;
    int start = adj.begin()->first;
    int maxDist = -1, farthestNode = start;
    dfs(start, -1, 0, adj, maxDist, farthestNode);
    maxDist = -1;
    dfs(farthestNode, -1, 0, adj, maxDist, farthestNode);

    return maxDist;
}

void solve() {
    int n;cin >> n;
    unordered_map<int,vi> adj;
    for (int i = 0; i < n-1; ++i) {
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = n-1;
    if (getMaxPathDist(adj) == n-1){
        ans += n;
    }else{
        ans += 2;
    }
    cout << ans << endl;
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
