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

void solve() {
    int n;cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> m(n);
    vector<int> M(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            m[i] = a[i];
            M[i] = b[i];
        } else {
            m[i] = b[i];
            M[i] = a[i];
        }
    }

    vector<int> l1(n);
    vector<int> l2(n);

    if (n > 0) {
        l1[n - 1] = 1;
        l2[n - 1] = 1;
    }

    for (int i = n - 2; i >= 0; --i) {
        if (m[i + 1] > m[i]) {
            l1[i] = 1 + l1[i + 1];
        } else if (M[i + 1] > m[i]) {
            l1[i] = 1 + l2[i + 1];
        } else {
            l1[i] = 1;
        }

        if (m[i + 1] > M[i]) {
            l2[i] = 1 + l1[i + 1];
        } else if (M[i + 1] > M[i]) {
            l2[i] = 1 + l2[i + 1];
        } else {
            l2[i] = 1;
        }
    }

    int total_count = 0;
    for (int i = 0; i < n; ++i) {
        total_count += max(l1[i], l2[i]);
    }

    cout << total_count << endl;
}

int32_t main() {
    fast_io();
    setIO();
    int t;
    cin >> t;
    while (t--) solve();
}

