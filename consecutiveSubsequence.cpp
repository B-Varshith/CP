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
vi a;

void solve() {
    cin >> n;
    a.resize(n);
    rep(i, 0, n) cin >> a[i];

    int endd = 0;
    int maxSz = 0;
    unordered_map<int,int> dp;
    for (int i = 0; i < n; ++i) {
        dp[a[i]] = dp[a[i] - 1] + 1;
        if (maxSz < dp[a[i]]){
            maxSz = dp[a[i]];
            endd = a[i];
        }
    }

    vi ans;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == endd) {
            ans.push_back(i + 1);
            endd--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
    cout << endl;
}

int32_t main() {
    setIO();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
