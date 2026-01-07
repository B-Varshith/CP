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

int MOD = 1e9+7;

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

void solve() {
    int n;
    cin >> n;
    vector<char> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> dp(n+2, vi(n+2, 0));
    for (int i = 0; i <= n+1; i++) dp[n][i] = 1;

    for (int i = n-1; i >= 1; i--) {
        if (a[i] == 'f') {
            for (int l = 0; l <= n; l++) {
                dp[i][l] = dp[i+1][l+1];
            }
        } else {
            vector<int> prefix(n+2, 0);
            prefix[0] = dp[i+1][0];
            for (int j = 1; j <= n; j++) {
                prefix[j] = (prefix[j-1] + dp[i+1][j]) % MOD;
            }
            for (int l = 0; l <= n; l++) {
                dp[i][l] = prefix[l];
            }
        }
    }

    cout << dp[1][0] % MOD << "\n";
}

int32_t main() {
    fast_io();
    setIO();
    int t = 1;
    while (t--) solve();
}

