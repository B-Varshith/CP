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

void solve(){
    int n,pos;cin >> n >> pos;
    string s;cin >> s;
    int left = -1,right = n;
    for (int i = pos-1; i >= 0; --i) {
        if (s[i] == '#'){
            left = i;
            break;
        }
    }
    for (int i = pos; i < n; ++i) {
        if (s[i] == '#'){
            right = i;
            break;
        }
    }
    if(left == -1 && right == n){
        cout << 1 << endl;
        return;
    }
    if (pos == 1 || pos == n){
        cout << 1 << endl;
        return;
    }

    int ans = INT_MAX;
    if (left == -1){
        ans = min(pos,n-right)+1;
    }
    else if (right == n){
        ans = min(pos,left+1)+1;
    }

    cout << min(ans,min(pos,n+1-pos)) << endl;
}

int32_t main() {
    fast_io();
    setIO();
    int t;
    cin >> t;
    while (t--) solve();
}

