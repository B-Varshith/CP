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

class FenTree{
    int n;
    vi fen;
public:
    FenTree(int n){
        fen.resize(n+1,0);
    }
    void update(int idx,int delta){
        while (idx <= n){
            fen[idx] += delta;
            idx = idx + ((idx)&(-idx));
        }
    }
    int query(int idx){
        int ans = 0;
        while (idx <= n){
            ans += fen[idx];
            idx = idx - (idx&(-idx));
        }
        return ans;
    }
    int queryRange(int l,int r){
        if(l > r) return 0;
        return query(r) - query(l-1);
    }
};

class segTree{
    vi seg;
public:
    segTree(){
        seg.resize(4*1e6+1,0);
    }

    void update(int node,int idx,int start,int end){
        if (start == end){
            seg[node]++;
            return;
        }
        int mid = (start + end)/2;
        if (idx <= mid){
            update(2*node+1,idx,start,mid);
        }else{
            update(2*node+2,idx,mid+1,end);
        }
        seg[node] = seg[2*node+1]+seg[2*node+2];
    }

    int query(int node,int l,int r,int start,int end){
        if (l <= start && end <= r){
            return seg[node];
        }
        if(l > end || r < start){
            return 0;
        }
        int mid = (start + end)/2;
        int lsum = query(2*node+1,l,r,start,mid);
        int rsum = query(2*node+2,l,r,mid+1,end);
        return lsum+rsum;
    }
};

void solve(){
    int n;cin >> n;
    vi a(n);rep(i,0,n) cin >> a[i];

    map<int,int> freq;
    vi f1(n),f2(n);
    for (int i = 0; i < n; ++i) {
        freq[a[i]]++;
        f1[i] = freq[a[i]];
    }
    freq.clear();
    for (int i = n-1; i >= 0; --i) {
        freq[a[i]]++;
        f2[i] = freq[a[i]];
    }

    segTree tree;
    int ans = 0;
    for (int i = n-1; i >= 0; --i) {
        ans += tree.query(0,0,f1[i]-1,0,1e6);
        tree.update(0,f2[i],0,1e6);
    }

    cout << ans << endl;
}

int32_t main() {
    setIO();
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
