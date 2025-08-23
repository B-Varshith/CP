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

int query(int idx1,int idx2){
    cout << '?' << " " << idx1 << " " << idx2 << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void complete(vi &ans,int n){
    set<int> st;
    for (int i = 1; i <= n; ++i) {
        st.insert(i);
    }
    int idx = 0;
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == 0){
            idx = i;
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        st.erase(ans[i]);
    }
    ans[idx] = *st.begin();
}

void solve(){
    int n;cin >> n;
    vi ans(n+1,0);

    int prevIdx = 1;
    for (int i = 2; i <= n; ++i) {
        int ele1 = query(i, prevIdx);
        int ele2 = query(prevIdx,i);
        if (ele1 > ele2){
            ans[i] = ele1;
        }else{
            ans[prevIdx] = ele2;
            prevIdx = i;
        }
    }

    complete(ans,n);

    cout << "! ";
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout.flush();
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
