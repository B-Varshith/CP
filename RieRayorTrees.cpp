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

class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            if (size[rootA] < size[rootB])
                swap(rootA, rootB);

            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
    }
    bool same(int a, int b) {
        return find(a) == find(b);
    }
};

void solve(){
    int n;cin >> n;
    vi a(n);rep(i,0,n) cin >> a[i];
    vi ans(n+1,0);
    int ptr1 = find(a.begin(), a.end(),1) - a.begin(),
    ptr2 = find(a.begin(),a.end(),n) - a.begin();
    if (ptr1 < ptr2){
        cout << "Yes" << endl;
        DSU ds(n+1);
        for (int i = 0; i <= ptr2; ++i) {
            ds.unite(a[i],n);
        }
        for (int i = ptr2+1; i < n; ++i) {
            ds.unite(1,a[i]);
        }
        for (int i = 1; i <= n; ++i) {
            if (i != ds.find(i)){
                cout << i << " " << ds.find(i) << endl;
            }
        }
    }else{
        cout << "Do" << endl;
    }
}

int32_t main() {
    fast_io();
    setIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}