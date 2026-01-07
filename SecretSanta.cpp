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

vector<pair<int,int>> makePairs(vector<int> A, vector<int> B) {
    int n = (int)A.size();
    sort(B.begin(), B.end());
    for (int i = 0; i < n; i++) {
        if (A[i] == B[i]) {
            if (n == 1) return {};
            if (i + 1 < n) swap(B[i], B[i+1]);
            else swap(B[i], B[i-1]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (A[i] == B[i]) return {};
    }
    vector<pair<int,int>> res;
    for (int i = 0; i < n; i++) {
        res.emplace_back(A[i], B[i]);
    }
    return res;
}

void solve(){
    int n;cin >> n;
    vi a(n+1,0);rep(i,1,n+1) cin >> a[i];
    unordered_map<int,int> mp;
    for (int i = 1; i <= n; ++i) {
        if(!mp.count(a[i])){
            mp[a[i]] = i;
        }
    }
    cout << mp.size() << endl;
    set<int> st;
    for (int i = 1; i <= n; ++i) {
        st.insert(i);
    }
    vi ans(n+1,-1);
    for(auto &p : mp){
        ans[p.second] = p.first;
        st.erase(p.first);
    }
    vector<int> idxs,nums;
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == -1){
            idxs.push_back(i);
        }
    }
    for(int i : st){
        nums.push_back(i);
    }
    auto vec = makePairs(idxs,nums);
    for(auto &[idx,num] : vec){
        ans[idx] = num;
    }
    int idx = -1;
    bool exists = false;
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == -1){
            exists = true;
            idx = i;
            break;
        }
    }
    if (mp.size() == n-1 && exists){
        for (int i = 1; i <= n; ++i) {
            if (ans[i] == a[idx]){
                ans[i] = *st.begin();
                break;
            }
        }
        ans[idx] = a[idx];
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
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

