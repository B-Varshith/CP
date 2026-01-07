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

void solve(){
    int n,k;cin >> n >> k;
    unordered_map<int,set<int>> adj;
    for (int i = 0; i < n-1; ++i) {
        int u,v;cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int time = 0;
    set<int> st;
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() == 1){
            st.insert(i);
        }
    }
    while (time < k && !st.empty()){
        n -= (int)st.size();
        set<int> curr;
        for(int i : st){
            curr.insert(*adj[i].begin());
            adj[*adj[i].begin()].erase(i);
            adj[i].clear();
        }
        st.clear();
        st = curr;
        time++;
    }
    cout << max(n,(int)0) << endl;
}

int32_t main() {
    fast_io();
    setIO();
    int t;
    cin >> t;
    while (t--) solve();
}

