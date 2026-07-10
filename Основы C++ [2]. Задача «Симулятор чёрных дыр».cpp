#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <array>

using namespace std;

#define all(x) (x).begin(), (x).end()
using ll = long long;
using pll = array<ll, 2>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ll o;
    cin >> n >> o;
    vector<pll> v(n);
    for (int i = 0; i < n; i++) {
        ll w;
        cin >> w;
        v[i] = pll{w, i + 1};
    }
    sort(all(v));
    for (int i = 0; i < n; i++) {
        if (o > v[i][0]) {
            o += v[i][0];
        } else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n" << v[0][1];
    for (int i = 1; i < n; i++) {
        cout << " " << v[i][1];
    }
}


