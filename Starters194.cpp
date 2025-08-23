#include <iostream>
#include <cstring>
using namespace std;

bool visited[100][100];

int dfs(int **grid, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j])
        return 0;

    visited[i][j] = true;

    int count = 1;

    count += dfs(grid, i + 1, j, m, n);
    count += dfs(grid, i - 1, j, m, n);
    count += dfs(grid, i, j + 1, m, n);
    count += dfs(grid, i, j - 1, m, n);

    return count;
}

int countAttendees(int **grid, int m, int n) {
    int total = 0;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                int groupSize = dfs(grid, i, j, m, n);
                if (groupSize > 1) {
                    total += groupSize;
                }
            }
        }
    }

    return total;
}

int main() {
    int m, n;
    cin >> m >> n;

    int **grid;
    grid = new int *[m];
    for (int i = 0; i < m; i++)
        grid[i] = new int[n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    cout << countAttendees(grid, m, n);

    return 0;
}
