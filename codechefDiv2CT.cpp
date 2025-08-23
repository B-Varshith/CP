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

int MOD = 998244353;

void setIO(){
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

bool is_possible(int k, int n, const vector<int>& a, const vector<int>& b, const vector<int>& counts) {
    if (k < 0) return false;
    for (int j = 0; j <= k; ++j) {
        if (j >= n || counts[j] == 0) {
            return true;
        }
    }
    vector<bool> is_unavoidable(k + 1, false);
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i] && a[i] <= k) {
            is_unavoidable[a[i]] = true;
        }
    }
    int missable_count = 0;
    for (int j = 0; j <= k; ++j) {
        if (!is_unavoidable[j]) {
            missable_count++;
        }
    }
    return missable_count >= 2;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    vector<int> counts(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        counts[a[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        counts[b[i]]++;
    }

    int low = 0, high = n, ans = n;

    while (low <= high) {
        int mid = low + ((high - low) >> 2);
        if (is_possible(mid, n, a, b, counts)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
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
