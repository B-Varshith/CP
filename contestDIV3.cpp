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
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define endl '\n'

int MOD = 998244353;

void setIO(){
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

int n, m, q;
vi a;

map<int, vi> modMap;
map<int, int> breakMap;

int computeBreaks(const vi &x) {
    int cnt = 0;
    for (int i = 1; i < x.size(); ++i)
        if (x[i] < x[i-1]) cnt++;
    return cnt;
}

void updateG(int g, int idx, int new_val) {
    int new_mod = new_val % g;
    vi &x = modMap[g];
    int &breaks = breakMap[g];
    if (idx > 0) {
        if (x[idx] < x[idx-1]) breaks--;
        if (new_mod < x[idx-1]) breaks++;
    }
    if (idx + 1 < n) {
        if (x[idx+1] < x[idx]) breaks--;
        if (x[idx+1] < new_mod) breaks++;
    }

    x[idx] = new_mod;
}

void solve() {
    cin >> n >> m >> q;
    a.resize(n);
    rep(i, 0, n) cin >> a[i];

    while (q--) {
        int oper;
        cin >> oper;
        if (oper == 1) {
            int idx, ele;
            cin >> idx >> ele;
            --idx;
            for (auto &[g, x] : modMap) {
                updateG(g, idx, ele);
            }
            a[idx] = ele;
        }else {
            int k;
            cin >> k;
            int g = gcd(m, k);

            if (g == 1) {
                cout << "Yes\n";
                continue;
            }

            if (modMap.find(g) == modMap.end()) {
                vi x(n);
                rep(i, 0, n) x[i] = a[i] % g;
                modMap[g] = x;
                breakMap[g] = computeBreaks(x);
            }

            if (breakMap[g] < m / g)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    modMap.clear();
    breakMap.clear();
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