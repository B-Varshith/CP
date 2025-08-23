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

const int MAXN = 2e5 + 5;

long long fact[MAXN], invfact[MAXN];

long long power(long long a, long long b, int mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init_factorials() {
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invfact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2, MOD);
    for (int i = MAXN - 2; i >= 1; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
}

long long mulmod(long long a, long long b) {
    return (a % MOD) * (b % MOD) % MOD;
}

void solve(){
    int n;cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int,int> freq;
    for(int i : a) freq[i]++;
    int max_ele = 0,sec_max = 0;
    for(auto &p : freq){
        max_ele = max(max_ele,p.first);
    }
    for(auto &p : freq){
        if (p.first != max_ele){
            sec_max = max(sec_max,p.first);
        }
    }

    if (sec_max == 0){
        cout << fact[n] << endl;
        return;
    }

    if (max_ele - sec_max == 1 && freq[max_ele] == 1){

    }else{
        if (freq[max_ele] > 1){
            cout << fact[n] << endl;
        }else{
            cout << 0 << endl;
            return;
        }
    }
}

int32_t main() {
    setIO();
    int t = 1;
    cin >> t;
    init_factorials();
    while (t--) {
        solve();
    }
    return 0;
}
