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
    int n;
    vi seg;
public:
    segTree(int x){
        n = x;
        seg.resize(4*n+1);
        rep(i,0,4*n+1) seg[i] = 0;
    }

    void build(vector<int> &a,int l,int r,int node){
        if (l >= r) return;
        int mid = (l+r)/2;
        build(a,l,mid,2*node+1);
        build(a,mid+1,r,2*node+2);
        seg[node] = seg[2*node+1] + seg[2*node+2];
    }

    void update(int idx,int l,int r,int node){
        if(l == r){
            seg[node]++;
            return;
        }

        int mid = (l+r)/2;
        if (idx <= mid){
            update(idx,l,mid,2*node+1);
        }else{
            update(idx,mid+1,r,2*node+2);
        }

        seg[node] = seg[2*node+1] + seg[2*node+2];
    }

    int query(int start,int end,int left,int right,int node){
        if (start == left && end == right){
            return seg[node];
        }

        if (end < left || start > right) return 0;

        int mid = (start+end)/2;
        int leftSum = query(start,mid,left,min(right,mid),2*node+1);
        int rightSum = query(mid+1,end, max(left,mid+1),right,2*node+2);

        return leftSum + rightSum;
    }
};

void solve(){
    int n;cin >> n;
    vi a(n);rep(i,0,n) cin >> a[i];
    vector<int> arr(1e5+1,0);
    segTree tree(1e5);
    vector<int> ans(n,0);
    tree.build(arr,0,1e5,0);
    for (int i = 0; i < n; ++i) {
        tree.update(a[i],0,1e5,0);
        ans[i] = tree.query(0,1e5,a[i]+1,1e5,0);
    }

    for(int i : ans){
        cout << i << " ";
    }
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
