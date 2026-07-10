#include <iostream>
#include <array>

using namespace std;

#define all(x) (x).begin(), (x).end()
using ll = long long;
using pll = array<ll, 2>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    if (!(cin >> n >> k)) return 0;
    if (k > 60 || (1LL << k) > n) {
        cout << -1 << "\n";
        return 0;
    }
    ll c = n >> k;
    if (c % 2 == 0) {
        c--;
    }
    ll m = c << k;
    if (m > 0) {
        cout << m << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}