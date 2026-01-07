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

int changesTobeMade(int x,unordered_map<char,int> &freq,string &s){
    int n = (int)s.size();
    if (n%x != 0){
        return INT_MAX;
    }
    vector<int> v;
    for(auto &[ch,num] : freq){
        v.push_back(num);
    }
    sort(all(v),greater<>());
    if(x <= v.size()){
        int cnt = 0;
        for (int i = 0; i < x; ++i) {
            cnt += v[i];
        }
        return n - cnt;
    }else{
        int each = n/x;
        int cnt = 0;
        for(int i : v){
            if (i > each){
                cnt += i-each;
            }
        }
        return cnt;
    }
}

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    vector<int> v(27,INT_MAX);
    unordered_map<char,int> freq;
    for (int i = 0; i < n; ++i) {
        freq[s[i]]++;
    }
    for (int i = 1; i <= 26; ++i) {
        v[i] = changesTobeMade(i,freq,s);
    }
    int chars = -1,each = INT_MAX;
    for (int i = 1; i <= 26; ++i) {
        if (each > v[i]){
            each = v[i];
            chars = i;
        }
    }


}

int32_t main() {
    fast_io();
    setIO();
    int t;
    cin >> t;
    while (t--) solve();
}

