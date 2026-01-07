#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

struct Itersegtree{
    int n, def, t;
    vector <int> seg;
    inline int combine(int x, int y){
        if (t == 0){
            return min(x, y);
        } else {
            return max(x, y);
        }
    }
    inline void modify(int p, int v){
        p--;
        for (seg[p += n] = v; p > 1; p >>= 1)
            seg[p >> 1] = combine(seg[p], seg[p ^ 1]);
    }
    inline int query(int l, int r){
        l--;
        int res = def;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1){
            if (l & 1) res = combine(res, seg[l++]);
            if (r & 1) res = combine(res, seg[--r]);
        }
        return res;
    }
    Itersegtree (int _n, int _def, vector <int> a, int _t){
        n = _n;
        t = _t;
        def = _def;
        seg.resize(2 * n + 1);
        for (auto &x : seg){
            x = def;
        }
        for (int i = 1; i <= n; i++){
            if (a.size() == n) modify(i, a[i - 1]);
            else modify(i, a[i]);
        }
    }
};

void Solve(){
    int n, q; cin >> n >> q;
    vector <int> a(n);
    for (auto &x : a) cin >> x;
    auto b = a;
    auto c = a;
    for (int i = 0; i < n; i++){
        if (i % 2 == 0){
            c[i] = -INF;
        } else {
            b[i] = INF;
        }
    }

    Itersegtree segmn(n, INF, b, 0);
    Itersegtree segmx(n, -INF, c, 1);
    auto solve = [&](){
        int lo = 1, hi = n;
        while (lo != hi){
            int mid = (lo + hi) / 2;
            int v1 = segmn.query(mid, n);
            int v2 = segmx.query(mid, n);
            if (v1 >= v2){
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        int v1 = segmn.query(lo, n);
        int v2 = segmx.query(lo, n);
        if (lo % 2 == 0){
            cout << v2 << " ";
        } else {
            cout << v1 << " ";
        }
    };

    solve();
    while (q--){
        int p, x; cin >> p >> x;
        p--;
        a[p] = x;
        if (p % 2 == 0){
            segmn.modify(p + 1, x);
        }else {
            segmx.modify(p + 1, x);
        }
        solve();
    }
    cout << "\n";
}

int32_t main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    cin >> t;
    for(int i = 1; i <= t; i++){
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}