#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<long long> prefix;

long long getAns(const vector<long long>& a, int n, const vector<long long>& minPrefixEven, const vector<long long>& minPrefixOdd, int idx, const vector<int>& cnt) {
    long long evenEle, oddEle;
    if (idx & 1) {
        evenEle = cnt[idx - 1];
        oddEle = cnt[idx];
    } else {
        evenEle = cnt[idx];
        oddEle = cnt[idx - 1];
    }

    long long minOdd = minPrefixOdd[idx];
    long long minEven = minPrefixEven[idx];

    long long current_path_sum = prefix[idx];

    long long total_cost = current_path_sum;
    total_cost += (n - evenEle) * minEven;
    total_cost += (n - oddEle) * minOdd;

    return total_cost;
}

void solve(const vector<int>& cnt) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    prefix.resize(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefix[i] = a[i] + prefix[i-1];
    }
    vector<long long> minPrefixEven(n, LLONG_MAX), minPrefixOdd(n, LLONG_MAX);

    minPrefixEven[0] = a[0];
    for (int i = 2; i < n; i += 2) {
        minPrefixEven[i] = min(minPrefixEven[i - 2], a[i]);
    }

    if (n > 1) {
        minPrefixOdd[1] = a[1];
        for (int i = 3; i < n; i += 2) {
            minPrefixOdd[i] = min(minPrefixOdd[i - 2], a[i]);
        }
    }
    for (int i = 1; i < n; ++i) {
        if (i % 2 != 0 && minPrefixEven[i] == LLONG_MAX) {
            minPrefixEven[i] = minPrefixEven[i - 1];
        }
        if (i % 2 == 0 && minPrefixOdd[i] == LLONG_MAX) {
            minPrefixOdd[i] = minPrefixOdd[i - 1];
        }
    }

    long long ans = LLONG_MAX;

    for (int i = 1; i < n; ++i) {
        ans = min(ans, getAns(a, n, minPrefixEven, minPrefixOdd, i, cnt));
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    vector<int> cnt(100001);
    cnt[0] = 1;
    cnt[1] = 1;
    for (int i = 2; i <= 100000; i += 2) {
        cnt[i] = cnt[i - 2] + 1;
    }
    for (int i = 3; i <= 100000; i += 2) {
        cnt[i] = cnt[i - 2] + 1;
    }

    while (t--) {
        solve(cnt);
    }
    return 0;
}
