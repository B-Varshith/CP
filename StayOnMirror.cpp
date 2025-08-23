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

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int finalInversions = 0;

    for (int i = 1; i < n; ++i) {
        int invCnt1 = 0, invCnt2 = 0;

        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) invCnt1++;
            if (a[j] < 2 * n - a[i]) invCnt2++;
        }

        if (invCnt2 <= invCnt1) {
            a[i] = 2 * n - a[i];
            finalInversions += invCnt2;
        } else {
            finalInversions += invCnt1;
        }
    }

    cout << finalInversions << endl;
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
