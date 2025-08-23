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

int query(int l,int r){
    cout << "? " << l << " " << r << endl;
    cout.flush();
    int res;cin >> res;
    return res;
}

int bs(int l, int r, int smax) {
    if (smax < l){
        int ans;
        while (l <= r){
            int mid = (l+r)/2;
            if (query(smax,mid) == smax){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }else{
        int ans;
        while (l <= r){
            int mid = (l+r)/2;
            if (query(mid,smax) == smax){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return ans;
    }
}

void solve(){
    int n;cin >> n;
    int smax = query(1,n);
    int ans;
    if (smax == 1){
        ans = bs(2,n,1);
    }else if (smax == n){
        ans = bs(1,smax-1,smax);
    }else if (query(1,smax) == smax){
        ans = bs(1,smax-1,smax);
    }else{
        ans = bs(smax+1,n,smax);
    }
    cout << "! " << ans << endl;
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
