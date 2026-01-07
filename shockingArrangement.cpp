#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        if (*max_element(a.begin(), a.end()) == 0) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            long long prefix_sum = 0;
            vector<int> pos, neg, ans;

            for (int x : a) {
                if (x >= 0) pos.push_back(x);
                else neg.push_back(x);
            }

            reverse(pos.begin(), pos.end());
            reverse(neg.begin(), neg.end());

            for (int i = 0; i < n; ++i) {
                if (prefix_sum <= 0) {
                    ans.push_back(pos.back());
                    pos.pop_back();
                } else {
                    ans.push_back(neg.back());
                    neg.pop_back();
                }
                prefix_sum += ans.back();
            }

            for (int i = 0; i < n; ++i) {
                cout << ans[i] << (i + 1 == n ? '\n' : ' ');
            }
        }
    }

    return 0;
}
