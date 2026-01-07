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

int MOD = 1e9+7;

void setIO(){
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

int n,k;
void *dp;

int computeAns(int plateNo,int mass,int direction){
    if (plateNo <= 0 || plateNo > n || mass == 1) return 0;
    if (dp[plateNo][mass][direction] != -1) return dp[plateNo][mass][direction];

    int onn,too;
    if (direction == 0){
        onn = computeAns(plateNo+1,mass,0);
        too = 1 + computeAns(plateNo-1,mass-1,1);
    }else{
        onn = computeAns(plateNo-1,mass,1);
        too = 1 + computeAns(plateNo+1,mass-1,0);
    }

    return dp[plateNo][mass][direction] = (onn%MOD+too%MOD)%MOD;
}

void solve(){
    cin >> n >> k;
    memset(dp,-1, sizeof(dp));
    cout << 1 + computeAns(1,k,0) << endl;
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
