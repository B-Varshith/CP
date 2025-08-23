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

class segTree {
public:
    vector<int> seg;
    int n, height;

    segTree(int n_) {
        n = n_;
        seg.resize(4 * n + 1);
        height = __builtin_ctz(n);
    }

    void build(int idx, int left, int right, vector<int> &a, int depth) {
        if (left == right) {
            seg[idx] = a[left];
            return;
        }

        int mid = (left + right) / 2;
        build(2 * idx + 1, left, mid, a, depth - 1);
        build(2 * idx + 2, mid + 1, right, a, depth - 1);

        if (depth % 2 == 0)
            seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
        else
            seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
    }

    void update(int idx, int left, int right, int pos, int val, int depth) {
        if (left == right) {
            seg[idx] = val;
            return;
        }

        int mid = (left + right) / 2;
        if (pos <= mid)
            update(2 * idx + 1, left, mid, pos, val, depth - 1);
        else
            update(2 * idx + 2, mid + 1, right, pos, val, depth - 1);

        if (depth % 2 == 0)
            seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
        else
            seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    int N = 1 << n;
    vi a(N);
    rep(i, 0, N) cin >> a[i];

    segTree tree(N);
    tree.build(0, 0, N - 1, a, n+1);

    while (q--) {
        int idx, val;
        cin >> idx >> val;
        idx--;
        tree.update(0, 0, N - 1, idx, val, n+1);
        cout << tree.seg[0] << "\n";
    }
}


int32_t main() {
    setIO();
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
