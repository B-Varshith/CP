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
const int inf = 1e18;


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
    int n,s1,s2; cin >> n >> s1 >> s2;
    s1--, s2--;
    vector<bool> good(n,false);
    unordered_map<int,vi> g1,g2;
    int edges; cin >> edges;
    set<pair<int,int>> st;

    while(edges--){
        int u,v; cin >> u >> v;
        u--, v--;
        st.emplace(u,v);
        g1[u].push_back(v);
        g1[v].push_back(u);
    }
    cin >> edges;
    while(edges--){
        int u,v; cin >> u >> v;
        u--, v--;
        if(st.count({u,v}) || st.count({v,u})){
            good[u] = true;
            good[v] = true;
        }
        g2[u].push_back(v);
        g2[v].push_back(u);
    }

    vector<vector<int>> dist(n,vector<int>(n,inf));
    set<pair<int,pair<int,int>>> pq;

    pq.insert({0,{s1,s2}});
    dist[s1][s2] = 0;

    while(!pq.empty()){
        auto [d,uv] = *pq.begin();
        auto [u,v] = uv;
        pq.erase(pq.begin());

        if(d > dist[u][v]) continue;

        for(int to1 : g1[u]){
            for(int to2 : g2[v]){
                int w = abs(to1-to2);
                if(dist[to1][to2] > d + w){
                    int oldDist = dist[to1][to2];
                    pq.erase({oldDist,{to1,to2}});
                    dist[to1][to2] = d + w;
                    pq.insert({dist[to1][to2],{to1,to2}});
                }
            }
        }
    }

    int ans = inf;
    for(int i=0;i<n;i++){
        if(!good[i]) continue;
        ans = min(ans,dist[i][i]);
    }

    cout << ((ans==inf) ? -1 : ans) << "\n";
}

int32_t main() {
    fast_io();
    setIO();
    int t;
    cin >> t;
    while (t--) solve();
}

