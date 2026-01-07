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

void solve(){
    int n; cin >> n;
    vi a(n); rep(i,0,n) cin >> a[i];
    map<int,int> freq;
    for (int i = 0; i < n; ++i) {
        freq[a[i]]++;
    }
    bool ok = false;
    for (int i = 0; i < n; ++i) {
        if (freq[a[i]] != 1) {
            ok = true;
            break;
        }
    }
    if (!ok){
        cout << 0 << endl;
        return;
    }
    multiset<int> st;
    int peri = 0;
    vector<int> toErase;
    for (auto &[num, f] : freq){
        if (f > 1){
            if (f % 2 == 0){
                for (int i = 0; i < f; ++i) st.insert(num);
                peri += f * num;
                toErase.push_back(num);
            } else {
                for (int i = 0; i < f - 1; ++i) st.insert(num);
                peri += (f - 1) * num;
                freq[num] = 1;
            }
        }
    }
    for (int num : toErase) freq.erase(num);
    if ((int)freq.size() == 0 && (int)st.size() > 2){
        cout << peri << endl;
        return;
    }
    int fans = peri;
    int mx1 = INT_MIN;
    for (auto &[num, f] : freq){
        if (num < peri && num > mx1){
            mx1 = num;
        }
    }
    if (mx1 != INT_MIN) {
        freq.erase(mx1);
        peri += mx1;
    }
    int mx2 = INT_MIN;
    for (auto &[num, f] : freq){
        if (num < peri && num > mx2){
            mx2 = num;
        }
    }
    if (mx2 != INT_MIN) freq.erase(mx2);
    if (mx2 == INT_MIN && mx1 == INT_MIN){
        if (st.size() > 2){
            cout << fans << endl;
            return;
        } else {
            cout << 0 << endl;
            return;
        }
    }
    if (mx1 != INT_MIN && mx2 != INT_MIN){
        cout << mx2 + peri << endl;
        return;
    }
    if (mx1 != INT_MIN){
        if (st.size() >= 2){
            cout << peri << endl;
            return;
        } else {
            cout << 0 << endl;
            return;
        }
    }
}

int32_t main() {
    fast_io();
    setIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}