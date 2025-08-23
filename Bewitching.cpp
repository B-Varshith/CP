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

int ans,n;

void computeAns(int l,int r,int k){
    int mid = (l+r)/2;
    if (r-l+1 < k) return;

    if ((r-l+1)%2 == 0){
        computeAns(l,mid,k);
    }else{
        int temp = mid;
        ans += temp;
        while (temp + l + r <= n){
            ans += temp + l + r;
            temp += (l+r);
        }
        computeAns(l,mid-1,k);
    }
}

void solve(){
    int k;cin >> n >> k;
    ans = 0;
    computeAns(1,n,k);
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
