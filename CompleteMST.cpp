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

bool isPossible(int k,int n,int m){
    return (k*n - (k*(k+1)/2)) <= m;
}
void solve(){
    int n,m;cin >> n >> m;
    int l = 0,r = n;
    int ans = 0;
    while (l <= r){
        int mid = l + (r-l)/2;
        if (isPossible(mid,n,m)){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    
    cout << ans*(ans+1)/2 << endl;
}

int32_t main() {
    fast_io();
    setIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}