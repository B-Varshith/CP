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

bool check(string &s,int needed,int k){
    int cnt = 0;
    int c = 0,z = 0;
    for (char i : s) {
        if (i == '0') z++;
        else c++;
        c = max(c,z);

        if (c == needed){
            cnt++;
            c = 0,z = 0;
        }
    }

    return cnt >= k;
}

void solve(){
    int n,k;cin >> n >> k;
    string s;cin >> s;
    int l = 1,r = n;
    int ans = 1;
    while (l <= r){
        int mid = l + ((r-l)>>1);
        if (check(s,mid,k)){
            ans = mid;
            l = mid+1;
        }else{
            r = mid - 1;
        }
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
