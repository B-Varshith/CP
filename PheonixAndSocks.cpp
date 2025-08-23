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
    long long l, r;
    std::cin >> n >> l >> r;
    std::map<int, int> left_counts, right_counts;
    for (int i = 0; i < l; ++i) {
        int color;
        std::cin >> color;
        left_counts[color]++;
    }
    for (int i = 0; i < r; ++i) {
        int color;
        std::cin >> color;
        right_counts[color]++;
    }
    for (auto const& [color, count] : left_counts) {
        if (right_counts.count(color)) {
            int matches = std::min(left_counts[color], right_counts[color]);
            left_counts[color] -= matches;
            right_counts[color] -= matches;
            l -= matches;
            r -= matches;
        }
    }
    if (l < r) {
        std::swap(l, r);
        std::swap(left_counts, right_counts);
    }
    long long conversions_needed = (l - r) / 2;
    long long majority_pairs = 0;
    for (auto const& [color, count] : left_counts) {
        majority_pairs += count / 2;
    }
    long long smart_conversions = std::min(conversions_needed, majority_pairs);
    long long cost = conversions_needed + (l + r) / 2 - smart_conversions;
    cout << cost << endl;
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
