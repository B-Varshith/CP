#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
const int64 LIM = 2e18;

int bfs(int64 N) {
    if (N == 1) return 0;
    if (N == 2 || N == 3)return 1;
    if (N == 6) return 2;

    unordered_set<int64> vis;
    queue<pair<int64,int>> q;
    q.emplace(N, 0);
    vis.insert(N);

    while (!q.empty()) {
        auto [cur, steps] = q.front();
        q.pop();

        if (cur == 1) return steps;

        if (cur % 2 == 1) {
            int64 nxt = (cur ^ 3) + 1;
            if (nxt % 2 == 1) continue;
            if (nxt > LIM) continue;

            if (!vis.count(nxt)) {
                vis.insert(nxt);
                q.emplace(nxt, steps + 1);
            }
        } else {
            int64 d = cur / 2;
            if (!vis.count(d)) {
                vis.insert(d);
                q.emplace(d, steps + 1);
            }

            if ((cur & 3) != 0) {
                int64 nxt = (cur ^ 3) + 1;
                if (nxt <= LIM && !vis.count(nxt)) {
                    vis.insert(nxt);
                    q.emplace(nxt, steps + 1);
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int64 N;
        cin >> N;
        cout << bfs(N) << "\n";
    }
    return 0;
}
