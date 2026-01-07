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

struct Node {
    long long sum, pref, suff, best;
    Node(long long v = 0) {
        sum = v;
        pref = suff = best = v;
    }
};

Node mergeNode(const Node &L, const Node &R) {
    Node res;
    res.sum = L.sum + R.sum;
    res.pref = max(L.pref, L.sum + R.pref);
    res.suff = max(R.suff, R.sum + L.suff);
    res.best = max({L.best, R.best, L.suff + R.pref});
    return res;
}

struct SegTree {
    int n;
    vector<Node> tree;
    SegTree(int n) : n(n), tree(4*n) {}
    void build(vector<long long> &a, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = Node(a[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(a, idx*2, l, mid);
        build(a, idx*2+1, mid+1, r);
        tree[idx] = mergeNode(tree[idx*2], tree[idx*2+1]);
    }
    void build(vector<long long> &a) {
        build(a, 1, 0, n-1);
    }
    void update(int idx, int l, int r, int pos, long long val) {
        if (l == r) {
            tree[idx] = Node(val);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(idx*2, l, mid, pos, val);
        else update(idx*2+1, mid+1, r, pos, val);
        tree[idx] = mergeNode(tree[idx*2], tree[idx*2+1]);
    }
    void update(int pos, long long val) {
        update(1, 0, n-1, pos, val);
    }
    long long get_max_subarray() {
        return tree[1].best;
    }
};

void solve(){
    int n, k;
    cin >> n >> k;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    SegTree st(n);
    st.build(a);
    if (k % 2 == 0) {
        cout << st.get_max_subarray() << "\n";
        return;
    }
    long long ans = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        long long old = a[i];
        long long modified = a[i] + b[i];
        st.update(i, modified);
        ans = max(ans, st.get_max_subarray());
        st.update(i, old);
    }
    cout << ans << "\n";
}

int32_t main() {
    fast_io();
    setIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
}