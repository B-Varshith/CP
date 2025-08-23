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
    int n;cin >> n;
    vi a(n);rep(i,0,n)cin >> a[i];
    sort(all(a));
    vi suffixGcd(n);
    suffixGcd[n-1] = a[n-1];
    for (int i = n-2; i >= 0; --i) {
        suffixGcd[i] = gcd(suffixGcd[i+1],a[i]);
    }
    int ans = a[0]*suffixGcd[1];
    for (int i = 1; i < n-1; ++i) {
        ans = gcd(ans,a[i]*suffixGcd[i+1]/suffixGcd[i]);
    }
    cout << ans << endl;
}

int32_t main() {
    setIO();
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
