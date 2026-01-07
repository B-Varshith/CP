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

void solve() {
    int n,k;cin >> n >> k;
    vi a(n);rep(i,0,n)cin >> a[i];
    vi temp = a;
    if (a.size() == 3){
        for (int i = 0; i < k; ++i) {
            int num1 = temp[temp.size()-1],num2 = temp[temp.size()-2];
            if(num1 == num2){
                num2 = temp[temp.size()-3];
            }
            for (int j = 1; j <= n; ++j) {
                if (j != num1 && j != num2){
                    temp.push_back(j);
                    break;
                }
            }
        }
    }else{
        for (int i = 0; i < k; ++i) {
            int num1 = temp[temp.size()-1],num2 = temp[temp.size()-2],num3 = temp[temp.size()-3];
            for (int j = 1; j <= n; ++j) {
                if (j != num1 && j != num2 && j != num3){
                    temp.push_back(j);
                    break;
                }
            }
        }
    }
    for (int i = n; i < temp.size(); ++i) {
        cout << temp[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    fast_io();
    setIO();
    int t;
    cin >> t;
    while (t--) solve();
}
