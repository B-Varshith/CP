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

#include <bits/stdc++.h>
using namespace std;

void generateCombinations(int idx, int k, vector<char>& arr,
                          vector<char>& curr, vector<set<char>>& result) {
    if ((int)curr.size() == k) {
        result.push_back(set<char>(curr.begin(), curr.end()));
        return;
    }
    if (idx >= (int)arr.size()) return;
    curr.push_back(arr[idx]);
    generateCombinations(idx + 1, k, arr, curr, result);
    curr.pop_back();
    generateCombinations(idx + 1, k, arr, curr, result);
}

vector<set<char>> getKCharCombinations(vector<char>& arr, int k) {
    vector<set<char>> result;
    vector<char> curr;
    generateCombinations(0, k, arr, curr, result);
    return result;
}

int countEqualSubarrays(const string &s, const string &t) {
    int n = s.size(), ans = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i]) cur++;
        else {
            ans += cur * (cur + 1) / 2;
            cur = 0;
        }
    }
    ans += cur * (cur + 1) / 2;
    return ans;
}

int getAns(string a, string b, set<char> &st) {
    for (int i = 0; i < (int)a.size(); ++i) {
        if (st.count(a[i])) {
            a[i] = b[i];
        }
    }
    return countEqualSubarrays(a, b);
}

void solve() {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;

    set<char> st;
    for (char c : a) st.insert(c);
    vector<char> v(st.begin(), st.end());

    int ans = 0;

    if (k >= (int)v.size()) {
        cout << n*(n+1)/2 << endl;
        return;
    }

    auto all = getKCharCombinations(v, k);

    if (all.empty()) {
        ans = countEqualSubarrays(a, b);
    } else {
        for (auto &temp : all) {
            ans = max(ans, getAns(a, b, temp));
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    fast_io();
    setIO();
    int t;
    cin >> t;
    while (t--) solve();
}

