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

void solve(){
    int l,r;cin >> l >> r;
    int n = r-l+1;
    vi a(n);rep(i,0,n)cin >> a[i];
    sort(all(a));
    vi cnt(18,0);
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j <= r; ++j) {
            if ((a[j]&(1<<i)) == (1<<i))cnt[i]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < 18; ++i) {
        if (cnt[i] > r+1 - cnt[i])ans += (1<<i);
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
