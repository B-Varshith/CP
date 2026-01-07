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

bool check(long long x, int n, long long k, const std::vector<long long>& a, const std::vector<long long>& prefix_sum) {
    if (prefix_sum[n] - x <= k) {
        return true;
    }

    for (int y = 1; y < n; ++y) {
        if (y > x) {
            break;
        }
        long long decrease_ops = x - y;
        long long new_val = a[0] - decrease_ops;
        long long sum_of_unchanged = prefix_sum[n - y] - a[0];
        long long new_sum = (y + 1) * new_val + sum_of_unchanged;
        if (new_sum <= k) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<long long> a(n);
    long long initial_sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        initial_sum += a[i];
    }
    if (initial_sum <= k) {
        std::cout << 0 << endl;
        return;
    }
    std::sort(a.begin(), a.end());
    std::vector<long long> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }
    long long low = 0, high = initial_sum, ans = initial_sum;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, n, k, a, prefix_sum)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    fast_io();
    setIO();
    int t;
    cin >> t;
    while (t--) solve();
}

