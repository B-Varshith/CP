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

struct custom_hash{
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void setIO(){
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

bool f(int mid,vector<pair<int,int>> &v,int totProducts){
    int n = (int)v.size();
    int ons = 2*totProducts - mid;
    int products = (mid - ons)/2;
    for (int i = 0; i < n; ++i) {
        if (products >= totProducts){
            break;
        }
        if (v[i].first <= products){
            products += v[i].second;
        }else{
            return false;
        }
    }

    return true;
}

void solve(){
    int n;cin >> n;
    vector<pair<int,int>> v(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].second;
        cin >> v[i].first;
        sum += v[i].second;
    }
    sort(all(v));
    int l = sum,r = 2*sum;
    int ans = 2*sum;
    while (l <= r){
        int mid = l + (r-l)/2;
        if (f(mid,v,sum)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    fast_io();
    setIO();
    int t = 1;
    while (t--) solve();
}
