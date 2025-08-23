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

int getAns(int maxi,int oper){
    while (maxi > 1){
        if (maxi%2 == 0){
            maxi /= 2;
            oper++;
        }else{
            maxi++;
            oper++;
        }
    }
    return oper;
}

vi primefactorisation(int n){
    vi ans;
    while (n%2 == 0){
        ans.push_back(2);
        n/=2;
    }
    for (int i = 3; i*i <= n; i+=2) {
        while (n%i == 0){
            ans.push_back(i);
            n/=i;
        }
    }
    if (n > 1) ans.push_back(n);
    return ans;
}

void solve(vi &twoPowers){
    int n;cin >> n;
    vi primeFactor = primefactorisation(n);
    unordered_map<int,int> freq;
    for(int i : primeFactor){
        freq[i]++;
    }
    int oper = 0;
    bool allEqual = true;
    int dummy = 0;
    for(auto p : freq){
        dummy = p.second;
        break;
    }
    for(auto &p : freq){
        if (dummy != p.second){
            allEqual = false;
            break;
        }
    }

    if (allEqual){
        oper = 0;
    }else oper = 1;

    int maxi = INT_MIN;
    for(auto &p : freq){
        maxi = max(maxi,p.second);
    }

    if (oper == 1 && maxi%2 == 1){
        maxi++;
    }

    int ans = INT_MAX;
    if (oper == 1){
        ans = min(getAns(*lower_bound(all(twoPowers),maxi),1), getAns(maxi,1));
    }else{
        ans = min(getAns(*lower_bound(all(twoPowers),maxi),1), getAns(maxi,0));
    }

    int pro = 1;
    for(auto &p : freq){
        pro *= p.first;
    }
    cout << pro << " " << ans << endl;
}

int32_t main() {
    setIO();
    int t = 1;
    vi powerOf2;
//    cin >> t;
    int i = 1;
    while (i <= 1e6){
        i *= 2;
        powerOf2.push_back(i);
    }
    while (t--) {
        solve(powerOf2);
    }
    return 0;
}
