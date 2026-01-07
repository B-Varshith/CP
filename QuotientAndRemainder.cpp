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

int isPossible(int mid,int k,vi &q,vi &r){
    int ptr1 = 0,ptr2 = mid;
    while (ptr1 <= mid){
        if ((r[ptr2]+1)*q[ptr1]+r[ptr2] > k){
            return false;
        }
        ptr1++;
        ptr2--;
    }
    return true;
}

void solve(){
    int n,k;cin >> n >> k;
    vi q(n),r(n);
    rep(i,0,n) cin >> q[i];
    rep(i,0,n) cin >> r[i];
    sort(all(q)),sort(all(r));
    int left = 0,right = n-1;
    int ans = 0;
    while (left <= right){
        int mid = left + (right - left)/2;
        if (isPossible(mid,k,q,r)){
            ans = mid+1;
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    fast_io();
    setIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}