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

vi query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cout.flush();

    int n = r - l + 1;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        assert(a[i] != -1);
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    assert(n != -1);
    int l = 1, r = n;
    while (l  < r) {
        int mid = (l + r) / 2;
        vi left = query(l, mid);
        int cnt = 0;
        for (int i : left) {
            if (i >= l && i <= mid) cnt++;
        }
        if (cnt % 2 == 0) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    cout << "! " << l << endl;
    cout.flush();
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
