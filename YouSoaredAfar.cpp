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
    int n;cin >> n;
    vi a(n),b(n);
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) cin >> b[i];

    if (a == b){
        cout << -1 << endl;
        return;
    }

    int same = 0;

    vi vec = b;
    reverse(all(vec));
    if (a == vec){
        cout << 0 << endl;
        return;
    }

    vector<pair<int,int>> mp(n+1);
    for (int i = 1; i <= n; ++i) {
        mp[i] = make_pair(a[i-1],b[i-1]);
    }

    map<pair<int,int>,int> cnt;
    for (int i = 0; i < n; ++i) {
        cnt[make_pair(a[i],b[i])] = i+1;
    }

    bool ok = true;
    for(auto &p : cnt){
        int x = p.first.first;
        int y = p.first.second;
        if (cnt[{y,x}] == 0){
            ok = false;
            break;
        }
    }

    if (ok){
        vector<pii> ans;
        if (n&1) {
            for (int i = 1; i <= n; ++i) {
                if (mp[i].first == mp[i].second) {
                    int idx = (n + 1) >> 1;

                    cnt[mp[i]] = idx;
                    cnt[mp[idx]] = i;

                    swap(mp[i], mp[idx]);
                    ans.emplace_back(i, idx);
                    break;
                }
            }
        }
        for (int i = 1; i <= n/2; ++i) {
            auto [x,y] = mp[i];
            int idx = cnt[{y,x}];
            if (i != n - idx + 1){
                cnt[mp[idx]] = n-i+1;
                cnt[mp[n-i+1]] = idx;
                swap(mp[idx],mp[n-i+1]);
                ans.emplace_back(idx,n-i+1);
            }
        }

        for (int i = 1; i <= n; ++i) {
            if(mp[i].first == mp[i].second) same++;
        }

        if (n%2 == 0){
            if (same != 0){
                cout << -1 << endl;
                return;
            }
        }else{
            if (same != 1){
                cout << -1 << endl;
                return;
            }
        }

        cout << ans.size() << endl;
        for(auto &p : ans){
            cout << p.first << " " << p.second << endl;
        }
        return;
    }else{
        cout << -1 << endl;
        return;
    }
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
