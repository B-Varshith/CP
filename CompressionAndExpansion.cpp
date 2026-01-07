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

int stringToNumber(std::string s) {
    size_t last_dot_pos = s.find_last_of('.');
    if (last_dot_pos == std::string::npos) {
        return stoi(s);
    }
    return stoi(s.substr(last_dot_pos + 1));
}

void solve() {
    int n;
    std::cin >> n;
    std::stack<std::string> stk;
    std::vector<std::string> ans;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        if (i == 0) {
            std::string str = "1";
            ans.push_back(str);
            stk.push(str);
            continue;
        }
        if (num == 1) {
            std::string str = stk.top();
            str += ".1";
            ans.push_back(str);
            stk.push(str);
            continue;
        }
        while (!stk.empty() && stringToNumber(stk.top()) + 1 != num) {
            stk.pop();
        }
        std::string str = stk.top();
        stk.pop();
        size_t last_dot = str.find_last_of('.');
        if (last_dot != std::string::npos) {
            str.resize(last_dot + 1);
        } else {
            str.clear();
        }
        str += std::to_string(num);
        ans.push_back(str);
        stk.push(str);
    }
    for (const auto &str : ans) {
        std::cout << str << "\n";
    }
}

int32_t main() {
    fast_io();
    setIO();
    int t;
    cin >> t;
    while (t--) solve();
}

