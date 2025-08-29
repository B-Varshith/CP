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

void solve(){
    int n;cin >> n;
    vi a;rep(i,1,n+1)a.push_back(i);
    unordered_map<int,int> mp;
    for (int i = 1; i <= n; ++i) {
        cout << "? " << i << " " << n << " ";
        for(int j=1; j<=n; ++j) cout << j << " ";
        cout << endl;
        cout.flush();
        cin >> mp[i];
    }

    map<int,vi> list;
    for(auto p : mp){
        list[p.second].push_back(p.first);
    }

    int maxSrc = 0;
    int maxSz = 0;
    for(auto p : list){
        if (maxSz < p.first){
            maxSz = p.first;
            maxSrc = p.second[0];
        }
    }
    vector<int> ans;
    ans.push_back(maxSrc);
    int len_to_find = maxSz - 1;

    while (ans.size() < maxSz){
        for(int i : list[len_to_find]){
            cout << "? " << ans.back() << " " << 2 << " " << ans.back() << " " << i << endl;
            cout.flush();
            int res; cin >> res;
            if (res == 2){
                ans.push_back(i);
                len_to_find--;
                break;
            }
        }
    }

    cout << "! " << ans.size() << " ";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << endl;
    cout.flush();
}

int32_t main() {
    fast_io();
    setIO();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

