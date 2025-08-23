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
vi prefix;

int getNum(int one,int two){
    int x = one+two-1;
    int sum = prefix[x];
    sum += (x*(x+1)/2 - (one-1)*one/2);
    return sum;
}

int calculate_sum(int c, int coins) {
    int c2 = coins - c;
    int c1 = 2 * c - coins;
    if (c1 < 0 || c2 < 0) return INT_MIN;
    return getNum(c1, c2);
}

int getMaxOfAll(int coins) {
    int low_c = (coins + 1) / 2;
    int high_c = min(n, coins);
    if (low_c > high_c) {
        return 0;
    }
    int l = low_c, r = high_c;
    while (r - l >= 3) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (calculate_sum(m1, coins) < calculate_sum(m2, coins)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    int max_val = 0;
    for (int c = l; c <= r; ++c) {
        max_val = max(max_val, calculate_sum(c, coins));
    }
    return max_val;
}

void solve(){
    cin >> n;
    vi a(n);rep(i,0,n) cin >> a[i];
    sort(all(a),greater<>());
    prefix.resize(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; ++i) prefix[i] = prefix[i-1] + a[i];

    for (int k = 1; k <= 2*n; ++k) {
        cout << getMaxOfAll(k) << " ";
    }
    cout << endl;
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
