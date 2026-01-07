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

int countNonSetBits(int n) {
    if (n == 0) return 1;
    int zeros = 0;
    bool msbFound = false;
    for (int i = 31; i >= 0; i--) {
        if (n & (1u << i)) {
            msbFound = true;
        }
        if (msbFound) {
            if ((n & (1u << i)) == 0)
                zeros++;
        }
    }
    return zeros;
}

int dfs(int bit, int n, int k) {
    if (bit > 31) return 0;
    int max_val = dfs(bit + 1, n, k);
    int target = ((n >> bit) + 1) << bit;
    int diff = target - n;
    int moves_needed = __builtin_popcountll(diff);
    if (moves_needed <= k) {
        int current_score = __builtin_popcountll(n) + k - __builtin_popcountll(target);
        max_val = max(max_val, current_score);
    }
    return max_val;
}

void solve(){
    int n,k;cin >> n >> k;
    int bits = countNonSetBits(n);
    if (bits <= k){
        map<pair<int,int>,int> dp;
        cout << dfs(n,k,dp) << endl;
    }else{
        cout << bits + k - 1 << endl;
    }
}

int32_t main() {
    fast_io();
    setIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}