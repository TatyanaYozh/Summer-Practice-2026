#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<long long>> clouds(n, vector<long long>(4, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> clouds[i][j];
        }
    }
    int m;
    cin >> m;
    vector<vector<long long>> wind(m + 1, vector<long long>(2, 0));
    for (int i = 1; i <= m; i++) {
        long long val;
        cin >> val;
        wind[i][0] = wind[i - 1][0] + val;
        cin >> val;
        wind[i][1] = wind[i - 1][1] + val;

    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        long long x, y;
        int t;
        cin >> x >> y >> t;
        x -= wind[t][0];
        y -= wind[t][1];;
        bool rain = false;
        for (int i = 0; i < n; i++) {
            rain = (min(clouds[i][0], clouds[i][2]) <= x && min(clouds[i][1], clouds[i][3]) <= y &&
                max(clouds[i][2], clouds[i][0]) >= x && max(clouds[i][3], clouds[i][1]) >= y);
            if (rain) {
                break;
            }
        }
        if (rain) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
