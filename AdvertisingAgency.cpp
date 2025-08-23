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
    int n,k;cin >> n >> k;
    vi a(n);rep(i,0,n)cin >> a[i];
    map<int,int> freq;
    for (int i = 0; i < n; ++i) {
        freq[a[i]]++;
    }
    sort(all(a),greater<>());
    int maxPossible = 0;
    for (int i = 0; i < k; ++i) {
        maxPossible += a[i];
    }
    int lastIncl = a[k-1];
    int lastInclEle = 0;
    for (int i = k-1; i >= 0; --i) {
        if (a[i] == lastIncl) lastInclEle++;
    }
    cout << nCr_mod(freq[lastIncl],lastInclEle,MOD) << endl;
}

int32_t main() {
    setIO();
    int t = 1;
    cin >> t;
    precompute(MOD);
    while (t--) {
        solve();
    }
    return 0;
}
