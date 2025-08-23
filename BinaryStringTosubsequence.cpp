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
    set<int> ons,zrs;
    int cnt = 1;
    vi ans(n,0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0'){
            if (zrs.empty()){
                ons.insert(cnt);
                ans[i] = cnt;
                cnt++;
            }else{
                int ele = *zrs.begin();
                ans[i] = ele;
                ons.insert(ele);
                zrs.erase(ele);
            }
        }else{
            if (ons.empty()){
                zrs.insert(cnt);
                ans[i] = cnt;
                cnt++;
            }else{
                int ele = *ons.begin();
                ans[i] = ele;
                zrs.insert(ele);
                ons.erase(ele);
            }
        }
    }

    cout << cnt-1 << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
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
