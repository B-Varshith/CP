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

int compute(vi &a,int k,int z){
    int ans = INT_MIN;
    for (int backWards = 0; backWards <= z; ++backWards) {
        int front = k - 2*backWards;
        int maxi = INT_MIN;
        for (int i = 0; i <= front; ++i) {
            if (i < a.size()-1)maxi = max(maxi,a[i]+a[i+1]);
        }
        int curr = 0;
        for (int i = 1; i <= front; ++i) {
            curr += a[i];
        }
        curr += backWards*maxi;
        ans = max(ans,curr);
    }
    return ans;
}

void solve(){
    int n,k,z;cin >> n >> k >> z;
    vi a(n);
    a.resize(n);
    rep(i,0,n)cin >> a[i];
    int ans = a[0] + compute(a,k,z);
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