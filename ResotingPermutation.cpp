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
    vi a(n);rep(i,0,n)cin >> a[i];
    vi ansmax(n,0),ansmin(n,0);

    ansmin[0] = a[0];ansmax[0] = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i-1]){
            ansmax[i] = a[i];
            ansmin[i] = a[i];
        }
    }

    set<int> st;
    for (int i = 1; i <= n; ++i) st.insert(i);
    for (int i = 0; i < n; ++i) st.erase(a[i]);

    priority_queue<int, vector<int>, greater<>> minHeap;
    for(int i : st){
        minHeap.push(i);
    }
    for (int i = 0; i < n; ++i) {
        if (ansmin[i] == 0){
            ansmin[i] = minHeap.top();
            minHeap.pop();
        }
    }

    priority_queue<int> maxHeap;
    vector<bool> visited(n+1,false);
    visited[0] = true;
    for(int i : a) visited[i] = true;
    for (int i = 0; i < n; ++i) {
        if (ansmax[i] == 0) {
            if (!maxHeap.empty()) {
                ansmax[i] = maxHeap.top();
                maxHeap.pop();
            }
        } else {
            int ele = a[i] - 1;
            while (ele >= 1 && !visited[ele]) {
                maxHeap.push(ele);
                visited[ele] = true;
                ele--;
            }
        }
    }

    for(int i : ansmin)cout << i << " ";
    cout << endl;
    for(int i : ansmax)cout << i << " ";
    cout << endl;
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
