#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int MOD = 998244353;
int inf = 1e18;
void *dp;

void setIO(){
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

int compute(int a, int b, int k) {
    if (a == 0 && b == 0) return 0;
    if (k == 0) return inf;
    if (dp[a][b][k] != inf) return dp[a][b][k];

    int notPick = compute(a, b, k - 1);
    int pick1 = inf, pick2 = inf;
    if (a >= k) pick1 = (1LL << k) + compute(a - k, b, k - 1);
    if (b >= k) pick2 = (1LL << k) + compute(a, b - k, k - 1);

    return dp[a][b][k] = min({notPick, pick1, pick2});
}


void solve(){
    int x, y;
    cin >> x >> y;
    int ans = inf;
    for (int i = 57; i >= 0; --i) {
        for (int j = 57; j >= 0 ; --j) {
            if ((x>>i) == (y>>j)){
                ans = min(ans, compute(i,j,57));
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {
    setIO();
    int t = 1;
    cin >> t;
    for (auto & i : dp) {
        for (auto & j : i) {
            for (int & k : j) {
                k = inf;
            }
        }
    }
    while (t--) {
        solve();
    }
    return 0;
}
