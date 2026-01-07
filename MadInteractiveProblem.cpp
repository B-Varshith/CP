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

int query(std::vector<int> s) {
    cout << "? " << s.size() << ' ';
    std::sort(s.begin(), s.end());
    for (int u : s) cout << u << ' ';
    cout << '\n';
    int x; cin >> x; return x;
}
void solve() {
    int n; cin >> n; int m = 2 * n;
    std::vector<int> ans(m + 1), s, t;
    for (int i = 1; i <= m; ++i) {
        s.push_back(i);
        int r = query(s);
        if (r > 0)
            ans[i] = r, s.pop_back(), t.push_back(i);
    }
    for (int i = 1; i <= m; ++i) if (ans[i] == 0)
            t.push_back(i), ans[i] = query(t), t.pop_back();
    cout << "! ";
    for (int i = 1; i <= m; ++i)
        cout << ans[i] << " \n"[i == m];
}

int32_t main() {
    fast_io();
    setIO();
    int t;
    cin >> t;
    while (t--) solve();
}

