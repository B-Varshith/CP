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
    int n,l,r,k;
    int a1 = 0,a2 = 0;
    for (int i = l; i < r; ++i) {
        if ((i^(i+1)) >= l && (i^(i+1)) <= r){
            a1 = i;
            a2 = i+1;
            break;
        }
    }
    if (n == 2){
        cout << -1 << endl;
        return;
    }
    if ((n-2)%2 == 0){
        if (k == 1){
            cout << a1 << endl;
            return;
        }else if (k == 2){
            cout << a2 << endl;
            return;
        }else{
            cout << (a1^a2) << endl;
            return;
        }
    }
    cout << -1 << endl;
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
