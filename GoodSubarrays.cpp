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

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    vi prefix(n);
    prefix[0] = s[0] - '0';
    for (int i = 1; i < n; ++i) {
        prefix[i] = (s[i] - '0') + prefix[i-1];
    }
    map<int,int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; ++i) {
        mp[prefix[i] - i - 1]++;
    }
    int ans = 0;
    for(auto &p : mp){
        int x = p.second;
        ans += x*(x-1)/2;
    }
    cout << ans << endl;
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
