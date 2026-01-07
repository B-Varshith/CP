#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define INF(t) numeric_limits<t>::max()

int n;
vector<ll> v;
vector<vector<int>> adj;
void *dp;

void dfs(int x, int p) {
    dp[x][0] = -v[x];
    dp[x][1] = v[x];
    if(p!=-1 && dp[p][1] > 0) dp[x][0] += dp[p][1];
    if(p!=-1 && dp[p][0] > 0) dp[x][1] += dp[p][0];

    for(auto y : adj[x]) {
        if(y == p) continue;
        dfs(y, x);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        v.clear(); v.resize(n);
        for(auto &x : v) cin >> x;

        adj.clear(); adj.resize(n);
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dp.clear();
        dp = vector<vector<ll>>(n, vector<ll>(2, -INF(ll)));

        dfs(0, -1);

        for(int i = 0; i < n; i++) {
            cout << dp[i][1] << " ";
        }
        cout << "\n";
    }

    return 0;
}