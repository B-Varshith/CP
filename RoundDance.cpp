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

struct custom_hash{
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void setIO(){
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

class DSU {
    vector<int> parent;
public:
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }
    int findParent(int u) {
        if (parent[u] != u) parent[u] = findParent(parent[u]);
        return parent[u];
    }
    void unite(int u, int v) {
        int rootu = findParent(u), rootv = findParent(v);
        if (rootu != rootv) parent[rootv] = rootu;
    }
};

void solve(){
    int n;cin >> n;
    vi a(n+1);map<int,set<int>> adj;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (!adj[a[i]].count(i))adj[a[i]].insert(i);
        if (!adj[i].count(a[i]))adj[i].insert(a[i]);
    }
    unordered_map<int,vi> mp;
    set<int> vis;
    DSU ds(n+1);
    for (int i = 1; i <= n; ++i) {
        ds.unite(i,a[i]);
        ds.findParent(i);
    }
    for (int i = 1; i <= n; ++i) {
        vis.insert(ds.findParent(i));
    }
    int maxi = (int)vis.size();
    int canBeCombined = 0;
    for (int i = 1; i <= n; ++i) {
        mp[ds.findParent(i)].push_back((int)adj[i].size());
    }
    for(auto &[node,v] : mp){
        for(int i : v){
            if (i == 1){
                canBeCombined++;
                break;
            }
        }
    }
    if (canBeCombined == 0){
        cout << maxi << " " << maxi << endl;
        return;
    }
    cout << maxi - canBeCombined + 1 << " " << maxi << endl;
}

int32_t main() {
    fast_io();
    setIO();
    int t;
    cin >> t;
    while (t--) solve();
}

