#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<pii> go(string S) {
    vector<pii> ans;
    int N = S.size();

    while (true) {
        bool allZero = true;
        for (char c : S) {
            if (c == '1') allZero = false;
        }
        if (allZero) break;
        int L = 0, R = 2;
        for (int i = 0; i < N - 1; i++) {
            if (S[i] == S[i + 1]) {
                L = i;
                R = i;
                for (int j = i + 1; j < N; j++) {
                    if (S[j] == S[i]) R++;
                    else break;
                }
                break;
            }
        }
        for (int i = L; i <= R; i++) {
            S[i] = '0' + '1' - S[i];
        }
        ans.push_back({L, R});
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    if (s1 == s2) {
        cout << 0 << endl;
        return;
    }
    vector<pii> v1 = go(s1);
    vector<pii> v2 = go(s2);

    cout << v1.size() + v2.size() << endl;
    for (auto p : v1) {
        cout << p.first+1 << " " << p.second+1 << endl;
    }
    for (int i = (int)v2.size() - 1; i >= 0; --i) {
        cout << v2[i].first+1 << " " << v2[i].second+1 << endl;
    }
}

int32_t main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}