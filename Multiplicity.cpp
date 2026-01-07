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

int n;vi a;

void solve(){
    cin >> n;
    a.resize(n);
    rep(i,0,n)cin >> a[i];
    vector<int> next(n+2, 1), curr(n+2, 0);
    for (int idx = n-1; idx >= 0; idx--) {
        for (int sz = n; sz >= 1; sz--) {
            int notPick = next[sz];
            int pick = 0;
            if (a[idx] % sz == 0) pick = next[sz+1];
            curr[sz] = notPick + pick;
        }
        next = curr;
    }
    cout << next[1]-1 << endl;
}

int32_t main() {
    fast_io();
    setIO();
    int t = 1;
    while (t--) solve();
}
