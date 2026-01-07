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

int f(int mid,vi &a){
    int ans = 0;
    for(int i : a){
        ans += abs(mid - i);
    }
    return ans;
}

int Means(int l,int r,int mean,vi &a){
    if (mean >= l && mean <= r){
        return f(mean,a);
    }
    if (abs(mean - l) > abs(mean - r)){
        return f(r,a);
    }
    return f(l,a);
}

void solve(){
    int n,l,r;cin >> n >> l >> r;
    vi a(n);rep(i,0,n) cin >> a[i];
    sort(all(a));
    int mean = ((int)accumulate(all(a),0))/n;
    int ans = LLONG_MAX;
    for (int i = -1000; i <= 1000; ++i) {
        ans = min(ans, Means(l,r,mean-i,a));
    }
    cout << ans << endl;
}

int32_t main() {
    fast_io();
    setIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}