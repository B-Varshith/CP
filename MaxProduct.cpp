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

void check_segment(int start, int end, int n, const std::vector<int>& a, int& max_twos, int& l, int& r) {
    if (start > end) {
        return;
    }
    int neg_count = 0;
    int first_neg = -1, last_neg = -1;
    for (int i = start; i <= end; ++i) {
        if (a[i] < 0) {
            neg_count++;
            if (first_neg == -1) {
                first_neg = i;
            }
            last_neg = i;
        }
    }

    if (neg_count % 2 == 0) {
        int current_twos = 0;
        for (int i = start; i <= end; ++i) {
            if (std::abs(a[i]) == 2) {
                current_twos++;
            }
        }
        if (current_twos > max_twos) {
            max_twos = current_twos;
            l = start;
            r = n - (end + 1);
        }
    } else {
        int twos_after_first_neg = 0;
        for (int i = first_neg + 1; i <= end; ++i) {
            if (std::abs(a[i]) == 2) {
                twos_after_first_neg++;
            }
        }
        if (twos_after_first_neg > max_twos) {
            max_twos = twos_after_first_neg;
            l = first_neg + 1;
            r = n - (end + 1);
        }
        int twos_before_last_neg = 0;
        for (int i = start; i < last_neg; ++i) {
            if (std::abs(a[i]) == 2) {
                twos_before_last_neg++;
            }
        }
        if (twos_before_last_neg > max_twos) {
            max_twos = twos_before_last_neg;
            l = start;
            r = n - last_neg;
        }
    }
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> zero_indices;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] == 0) {
            zero_indices.push_back(i);
        }
    }
    int max_twos = 0;
    int l_ans = n, r_ans = 0;

    int last_zero_idx = -1;
    for (int zero_idx : zero_indices) {
        check_segment(last_zero_idx + 1, zero_idx - 1, n, a, max_twos, l_ans, r_ans);
        last_zero_idx = zero_idx;
    }
    check_segment(last_zero_idx + 1, n - 1, n, a, max_twos, l_ans, r_ans);

    std::cout << l_ans << " " << r_ans << endl;
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
