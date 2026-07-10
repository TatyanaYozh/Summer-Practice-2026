#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    int start_x, start_y;
    cin >> start_x >> start_y;
    start_x--;
    start_y--;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    dist[start_x][start_y] = 0;
    q.push({start_x, start_y});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (grid[nx][ny] == '.' && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << dist[i][j] << (j == m - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}