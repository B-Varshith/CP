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

vi getDifference(string &s1,string &s2){
    int sz = (int)min(s1.size(),s2.size());
    vector<int> ans(sz,0);
    if (s1[0] != s2[0]) ans[0] = 1;
    for (int i = 1; i < sz; ++i) {
        if (s1[i] != s2[i]){
            ans[i] = ans[i-1]+1;
        }else{
            ans[i] = ans[i-1];
        }
    }
    return ans;
}

void solve(){
    int n,q;cin >> n >> q;
    string s;cin >> s;
    string str[6] = {"abc","bca","cab","acb","bac","cba"};
    vector<vector<int>> a(6);
    for (int i = 0; i < 6; ++i) {
        string s1;
        while (n > s1.size()){
            s1 += str[i];
        }
        a[i] = getDifference(s1,s);
    }
    while (q--){
        int l,r;cin >> l >> r;
        l--,r--;
        int ans = INT_MAX;
        for (int i = 0; i < 6; ++i) {
            if (l == 0){
                ans = min(ans,a[i][r]);
            }else{
                ans = min(ans,a[i][r] - a[i][l-1]);
            }
        }
        cout << ans << endl;
    }
}

int32_t main() {
    setIO();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
