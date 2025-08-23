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

int getAns(vi &a,vi &b,int n){
    int ans = 0;
    set<int> st1,st2;
    st1.insert(a[n-1]);
    st2.insert(b[n-1]);
    for (int i = n-2; i >= 0; --i) {
        if (st1.count(a[i])){
            ans = max(ans,i+1);
            break;
        }
        st1.insert(b[i+1]);
        st1.insert(a[i]);
    }
    for (int i = n-2; i >= 0; --i) {
        if (st2.count(b[i])){
            ans = max(ans,i+1);
            break;
        }
        st2.insert(a[i+1]);
        st2.insert(b[i]);
    }
    return ans;
}

void solve(){
    int n;cin >> n;
    vi a(n),b(n);
    rep(i,0,n)cin >> a[i];rep(i,0,n)cin >> b[i];
    int ans = 0;
    int idx = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) idx = i;
    }
    ans = getAns(a,b,n);
    cout << max(ans,idx+1) << endl;
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
