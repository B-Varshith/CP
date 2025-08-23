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
    vi a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != i){
            ok = false;
            break;
        }
    }
    if (ok){
        cout << 0 << endl;
        return;
    }

    int ptr1 = 1,ptr2 = n;
    while (ptr1 == a[ptr1]){
        ptr1++;
    }
    while (ptr2 == a[ptr2]){
        ptr2--;
    }

    bool found = false;
    for (int i = ptr1; i <= ptr2; ++i) {
        if (i == a[i]){
            found = true;
        }
    }

    if(found){
        cout << 2 << endl;
        return;
    }else{
        cout << 1 << endl;
    }
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
