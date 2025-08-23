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

vi primeFactorisation(int n){
    vi ans;
    while (n%2 == 0){
        ans.push_back(2);
        n /= 2;
    }
    for (int i = 3; i*i < n; i+=2) {
        while (n%i == 0){
            ans.push_back(i);
            n/=i;
        }
    }
    if (n > 1) ans.push_back(n);
    return ans;
}

void solve(vi &powersOf2){
    int n;cin >> n;
    if (((n+1)&n) == 0){
        vi primefactors = primeFactorisation(n);
        int pro = 1;
        for(int i : primefactors) pro *= i;
        if (pro == n){
            pro /= *min_element(all(primefactors));
        }
        cout << pro << endl;
        return;
    }else{
        cout << *upper_bound(all(powersOf2),n) - 1 << endl;
        return;
    }
}

int32_t main() {
    setIO();
    int t = 1;
    cin >> t;
    vi powersOf2;
    int num = 2;
    while (num < (1<<26)){
        powersOf2.push_back(num);
        num *= 2;
    }
    while (t--) {
        solve(powersOf2);
    }
    return 0;
}
