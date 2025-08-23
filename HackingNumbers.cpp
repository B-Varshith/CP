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

int digit(){
    cout << "digit" << endl;
    cout.flush();
    int res;cin >> res;
    return res;
}

int add(int num){
    cout << "add " << num << endl;
    cout.flush();
    int res;cin >> res;
    return res;
}

void solve(){
    int n;cin >> n;
    digit();
    digit();
    add(-4);
    add(-3);
    add(-2);
    add(-1);
    add(n-1);
    cout << "!" << endl;
    cout.flush();
    int res;
    if (cin >> res) assert(res);
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