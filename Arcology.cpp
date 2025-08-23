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

bool check(vi &a,int m){
    unordered_map<int,int> freq;
    for(int i : a) freq[i]++;
    for(auto &p : freq){
        if(p.second <= m){
            return false;
        }
    }
    return true;
}

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vi ans(n,0);
    int left = 1,right = n+1;

    if (n == 2){
        cout << 0 << " " << 0 << endl;
        return;
    }

    vi fans;
    while (left <= right){
        int mid = left + (right - left)/2;
        if (mid > k){
            for (int i = 0; i < n; ++i) ans[i] = i%mid;
        }else{
            for (int i = 0; i < n; ++i) ans[i] = i%k;
        }
        if(check(ans,m)){
            fans = ans;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    if(fans.empty()){
        for(int i : ans){
            cout << i << " ";
        }
    }else{
        for(int i : fans){
            cout << i << " ";
        }
    }
    cout << endl;
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
