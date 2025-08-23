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

class segTree{
    vi seg;
public:
    segTree(int n){
        seg.assign(4*n+1,0);
    }

    void build(vi &a,int l,int r,int node){
        if (l == r){
            seg[node] = a[l];
            return;
        }

        int mid = (l+r)/2;
        build(a,l,mid,2*node+1);
        build(a,mid+1,r,2*node+2);

        seg[node] = seg[2*node+1]&seg[2*node+2];
    }

    int query(int node,int start,int end,int l,int r){
        if (l > end || r < start) return ~0;

        if (l <= start && r >= end){
            return seg[node];
        }

        int mid = (start+end) >> 1;
        int ans = (1LL<<30)-1;
        ans &= query(2*node+1,start,mid,l,r);
        ans &= query(2*node+2,mid+1,end,l,r);

        return ans;
    }
};

void solve(){
    int n,m;cin >> n >> m;
    vi l(m+1),r(m+1),q(m+1);
    vi a(n,0);

    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i] >> q[i];
        l[i]--;
        r[i]--;
    }

    vi diffArray;
    for (int bit = 0; bit <= 30; ++bit) {
        diffArray.assign(n+1,0);
        for (int i = 0; i < m; ++i) {
            if (((1<<bit)&q[i]) > 0){
                diffArray[l[i]]++;
                diffArray[r[i]+1]--;
            }
        }
        for (int i = 1; i < n; ++i) {
            diffArray[i] += diffArray[i-1];
        }

        for (int i = 0; i < n; ++i) {
            if (diffArray[i] > 0){
                a[i] |= (1<<bit);
            }
        }
    }


    segTree tree(n);
    tree.build(a,0,n-1,0);

    for (int i = 0; i < m; ++i) {
        if (tree.query(0,0,n-1,l[i],r[i]) != q[i]){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    for(int i : a) cout << i << " ";
    cout << endl;
}

int32_t main() {
    setIO();
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
