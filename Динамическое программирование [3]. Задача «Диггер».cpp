#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gold(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> gold[i][j];
        }
    }
    vector<vector<int>> out(n, vector<int>(m, 0));
    out[0][0] = gold[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue;
            int before = 0;
            if (i > 0) {
                before = max(before, out[i - 1][j]);
            }
            if (j > 0) {
                before = max(before, out[i][j - 1]);
            }
            if (i > 0 && j > 0) {
                before = max(before, out[i - 1][j - 1]);
            }
            out[i][j] = before + gold[i][j];
        }
    }
    cout << out[n - 1][m - 1];
    return 0;
}