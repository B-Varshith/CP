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

bool checkSum(string &nums,int s){
    int sum = 0;
    for(auto i : nums){
        sum += i - '0';
    }

    if (sum <= s){
        return true;
    }
    return false;
}

void solve(){
    int nums;cin >> nums;
    int s;cin >> s;

    string n = to_string(nums);
    if (checkSum(n,s)){
        cout << 0 << endl;
        return;
    }else{
        int oper = 0;
        int num = 10;
        while (num < nums){
            num *= 10;
        }
        oper = num - nums;

        int intailNumber = nums;
        int sz = (int)n.size()-1;
        for (int i = sz; i > 0; --i) {
            if (n[i] == '0') continue;
            int needed = '9' - n[i];
            needed++;
            int add = needed*(pow(10,sz-i));
            nums += add;
            n = to_string(nums);
            if (checkSum(n,s)){
                cout << nums - intailNumber << endl;
                return;
            }
        }

        cout << oper << endl;
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
