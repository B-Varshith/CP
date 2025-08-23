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
public:
    vector<vector<int>> seg;
    segTree(int n){
        seg.assign(4 * n, vector<int>(3, 0));
    }

    vector<int> merge(const vector<int>& left, const vector<int>& right) {
        vector<int> result(3, 0);
        int new_pairs = min(left[0], right[1]);
        result[2] = left[2] + right[2] + new_pairs;
        result[0] = (left[0] - new_pairs) + right[0];
        result[1] = left[1] + (right[1] - new_pairs);
        return result;
    }

    void build(int idx,int l,int r,string &s){
        if (l == r){
            if (s[l] == '('){
                seg[idx][0] = 1;
            }else{
                seg[idx][1] = 1;
            }
            return;
        }

        int mid = (l+r)/2;
        build(2*idx+1,l,mid,s);
        build(2*idx+2,mid+1,r,s);

        seg[idx] = merge(seg[2*idx+1],seg[2*idx+2]);
    }

    vector<int> query(int idx, int l, int r, int low, int high) {
        if (r < low || l > high) {
            return vector<int>(3, 0);
        }
        if (l >= low && r <= high) {
            return seg[idx];
        }
        int mid = (l + r) / 2;
        vector<int> left = query(2 * idx + 1, l, mid, low, high);
        vector<int> right = query(2 * idx + 2, mid + 1, r, low, high);
        return merge(left, right);
    }
};

void solve(){
    string s;cin >> s;
    int q;cin >> q;
    segTree tree = segTree((int)s.size());
    int n = (int)s.size();
    tree.build(0,0,n-1,s);
    while (q--){
        int l,r;cin >> l >> r;
        l--,r--;
        vi ans = tree.query(0,0,n-1,l,r);
        cout << 2 * ans[2] << '\n';
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
