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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (int target = 0; target < 1024; ++target) {
        bool is_target_possible = true;
        for (int i = 0; i < n; ++i) {
            bool found_suitable_b = false;
            for (int j = 0; j < m; ++j) {
                int current_c = a[i] & b[j];
                if ((current_c | target) == target) {
                    found_suitable_b = true;
                    break;
                }
            }
            if (!found_suitable_b) {
                is_target_possible = false;
                break;
            }
        }
        if (is_target_possible) {
            std::cout << target << endl;
            return;
        }
    }
}

int32_t main() {
    setIO();
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

