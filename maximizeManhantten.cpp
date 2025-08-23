#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define int long long
#define f first
#define s second
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
    vector<pair<pii,int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].f.f >> v[i].f.s;
        v[i].s = i+1;
    }
    sort(all(v),[](auto &a,auto&b){
        if (a.f.f != b.f.f){
            return a.f.f < b.f.f;
        }
        return a.f.s <  b.f.s;
    });
    sort(v.begin(),v.begin()+n/2,[](auto& a,auto &b){
        return a.f.s < b.f.s;
    });
    sort(v.begin()+n/2,v.end(),[](auto& a,auto& b){
        return a.f.s > b.f.s;
    });

    for (int i = 0; i < n/2; ++i) {
        cout << v[i].s << " " << v[i+n/2].s << endl;
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
