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
int INF = 1e18;

struct custom_hash{
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void setIO(){
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

void solve() {
    int n; cin >> n;
    vi a(n), c(n);
    for (int &x : a) cin >> x;
    for (int &x : c) cin >> x;

    // Step 1: Coordinate compression
    vector<int> vals = a;
    vals.push_back(0); // dummy initial prev
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int m = vals.size(); // number of unique values

    // Step 2: DP initialization
    // dp[j] = min cost if previous value corresponds to vals[j]
    vector<int> dp(m, INF), newdp(m, INF);

    // Base case: first element
    for (int j = 0; j < m; ++j) {
        // If we don't change a[0]
        if (vals[j] <= a[0])
            dp[j] = 0;
        // If we change a[0]
        dp[j] = min(dp[j], c[0]);
    }

    // Step 3: Tabulate
    for (int i = 1; i < n; ++i) {
        fill(newdp.begin(), newdp.end(), INF);
        for (int j = 0; j < m; ++j) {
            if (dp[j] == INF) continue; // unreachable

            int prevVal = vals[j];

            // Option 1: Change current
            newdp[j] = min(newdp[j], dp[j] + c[i]);

            // Option 2: Not change (if non-decreasing)
            if (prevVal <= a[i]) {
                int newPrevIdx = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
                newdp[newPrevIdx] = min(newdp[newPrevIdx], dp[j]);
            }
        }
        dp.swap(newdp);
    }

    cout << *min_element(dp.begin(), dp.end()) << "\n";
}

int32_t main() {
    fast_io();
    setIO();
    int t;
    cin >> t;
    while (t--) solve();
}

