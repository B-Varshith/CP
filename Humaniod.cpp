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

int startWith3(vi &a,int pow){
    int ptr = 0;
    int threes = 1,twos = 2;
    while (ptr < (int)a.size()){
        if (pow > a[ptr]){
            pow += a[ptr]/2;
            ptr++;
        }else{
            if (threes > 0){
                pow *= 3;
                threes--;
                continue;
            }
            else if (twos > 0){
                pow *= 2;
                twos--;
                continue;
            }else{
                break;
            }
        }
    }
    return ptr;
}

int startWith2(vi &a,int pow){
    int ptr = 0;
    int threes = 1,twos = 2;
    while (ptr < (int)a.size()){
        if (pow > a[ptr]){
            pow += a[ptr]/2;
            ptr++;
        }else{
            if (twos > 0){
                pow *= 2;
                twos--;
                continue;
            }
            else if (threes > 0){
                pow *= 3;
                threes--;
                continue;
            }else{
                break;
            }
        }
    }
    return ptr;
}

int getAns232(vi &a,int pow){
    int ptr = 0;
    int threes = 1,twos = 2;
    bool used = false;
    while (ptr < (int)a.size()){
        if (pow > a[ptr]){
            pow += a[ptr]/2;
            ptr++;
        }else{
            if (twos > 0 && !used){
                pow *= 2;
                twos--;
                used = true;
                continue;
            }
            else if (threes > 0){
                pow *= 3;
                threes--;
                used = false;
                continue;
            }else{
                break;
            }
        }
    }
    return ptr;
}

void solve(){
    int n,h;cin >> n >> h;
    vi a(n);rep(i,0,n) cin >> a[i];
    sort(all(a));
    int ans =  max(startWith2(a,h),startWith3(a,h));
    ans = max(ans,getAns232(a,h));
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
