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

int findKthMissing(int k, oset<int> &st) {
    int low = 0, high = 1e9, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int missing = (mid + 1) - st.order_of_key(mid + 1);
        if (missing > k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}


void solve(){
    int n,q;cin >> n >> q;
    vi a(n);map<int,int> freq;
    rep(i,0,n){
        cin >> a[i];
        freq[a[i]]++;
    }
    oset<int> st;
    for(auto [x,f] : freq) st.insert(x);

    while (q--){
        int type;cin >> type;
        if (type == 1){
            int idx,x;cin >> idx >> x;
            idx--;
            if (--freq[a[idx]] == 0){
                st.erase(a[idx]);
            }
            if (++freq[x] == 1){
                st.insert(x);
            }
            a[idx] = x;
        }else if (type == 2){
            cout << findKthMissing(0,st) << endl;
        }else{
            int k;cin >> k;
            cout << findKthMissing(k,st) << endl;
        }
    }
}

int32_t main() {
    int t = 1;
    while (t--) solve();
}