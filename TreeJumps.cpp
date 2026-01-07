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

int n;
vector<int> level;
void *dp;
unordered_map<int,vi> adj;

void dfs(int node){
    for(int child : adj[node]){
        level[child] = level[node] + 1;
        dfs(child);
    }
}

void solve(){
    cin >> n;
    vi a(n+1,0);
    for (int i = 2; i <= n; ++i) {
        int x;cin >> x;
        a[i] = x;
        adj[x].push_back(i);
    }
    unordered_map<int,vi> children;
    for (int i = 2; i <= n; ++i) {
        children[a[i]].push_back(i);
    }

    level.assign(n+1,0);
    dfs(1);
    dp.assign(n+1,0);

    unordered_map<int,vi> levelEle;
    for (int i = 1; i <= n; ++i) levelEle[level[i]].push_back(i);

    int maxlevel = *max_element(all(level));
    for(int i : levelEle[maxlevel]){
        dp[i] = 1;
    }

    int temp = 1;
    for(int node : levelEle[maxlevel]){
        temp = (temp%MOD + dp[node]%MOD)%MOD;
    }

    for (int i = maxlevel-1; i >= 1; --i) {
        int sum = temp%MOD;
        temp = 1;
        for(int node : levelEle[i]){
            dp[node] = sum%MOD;
            for(int child : children[node]){
                dp[node] = (dp[node] - dp[child] + MOD)%MOD;
            }
            temp = (temp%MOD+dp[node]%MOD)%MOD;
        }
    }
    dp[1] = 1;
    for(int i : levelEle[1]){
        dp[1] = (dp[1]%MOD + dp[i]%MOD)%MOD;
    }
    cout << (dp[1]+MOD)%MOD << endl;
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