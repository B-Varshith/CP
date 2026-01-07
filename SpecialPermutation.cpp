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

void solve(vi &a){
    int n;cin >> n;
    if(n <= 3){
        cout << -1 << endl;
        return;
    }
    if (n == 4){
        cout << 2 << " " << 4 << " " << 1 << " " << 3 << endl;
        return;
    }
    if (n%5 == 0 || n%5 == 1){
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }else if (n%5 == 2){
        int nums[7] = {1,4,2,6,3,5,7};
        vector<int> ans(n+1,0);
        for (int i = 1; i <= n-7; ++i) {
            ans[i] = a[i];
        }
        int maxi = *max_element(all(ans));
        int ptr = 0;
        for (int i = n-6; i <= n; ++i) {
            ans[i] = maxi + nums[ptr++];
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }else if (n%5 == 3){
        int nums[8] = {1,5,2,6,3,7,4,8};
        vector<int> ans(n+1,0);
        for (int i = 1; i <= n-8; ++i) {
            ans[i] = a[i];
        }
        int maxi = *max_element(all(ans));
        int ptr = 0;
        for (int i = n-7; i <= n; ++i) {
            ans[i] = maxi + nums[ptr++];
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }else{
        int nums[9] = {1,4,2,5,3,7,9,6,8};
        vector<int> ans(n+1,0);
        for (int i = 1; i <= n-9; ++i) {
            ans[i] = a[i];
        }
        int maxi = *max_element(all(ans));
        int ptr = 0;
        for (int i = n-8; i <= n; ++i) {
            ans[i] = maxi + nums[ptr++];
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
}

int32_t main() {
    fast_io();
    setIO();
    int t;
    cin >> t;
    vi a(1001);
    int ptr = 1;
    while (ptr <= 1000){
        a[ptr] = ptr;
        a[ptr+2] = ptr+1;
        a[ptr+4] = ptr+2;
        a[ptr+1] = ptr+3;
        a[ptr+3] = ptr+4;
        ptr +=5;
    }
    while (t--) solve(a);
}

