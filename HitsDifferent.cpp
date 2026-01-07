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

vector<int> dp;
void solve(vector<vector<int>> &v, int m) {
    int hit;cin >> hit;
    if (dp[hit] != -1) {
        cout << dp[hit] << "\n";
        return;
    }
    int row = -1, col = -1;
    for (int i = 0; i < (int)v.size(); ++i) {
        for (int j = 0; j < (int)v[i].size(); ++j) {
            if (v[i][j] == hit) {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1) break;
    }
    int ans = 0;
    set<pair<int, int>> st;
    st.insert({row, col});
    while (row > 0) {
        int mini = 0, maxi = (int)v[row - 1].size() - 1;
        set<pair<int, int>> temp;
        for (auto &[r, c] : st) {
            temp.insert({r - 1, max(mini, c - 1)});
            temp.insert({r - 1, min(maxi, c)});
            ans += v[r][c] * v[r][c];
        }
        st = temp;
        row--;
    }
    dp[hit] = ans + 1;
    cout << dp[hit] << "\n";
}

int32_t main() {
    fast_io();
    setIO();
    dp.resize((2024*2023)/2, -1);
    vector<vector<int>> v;
    int sz = 1;
    int incr = 1;
    for (int i = 1; i <= 2023; ++i) {
        vector<int> temp;
        for (int j = 0; j < sz; ++j) {
            temp.push_back(incr++);
        }
        v.push_back(temp);
        sz++;
    }
    int t;
    cin >> t;
    while (t--) solve(v, incr);
    return 0;
}