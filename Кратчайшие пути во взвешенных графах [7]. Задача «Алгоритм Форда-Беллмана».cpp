#include <iostream>
#include <vector>

using namespace std;

#define all(x) (x).begin(), (x).end()
using ll = long long;

struct Edge {
    int u, v;
    ll w;
};

const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s;
    cin >> n >> m >> s;
    s--;

    vector<Edge> ar(m);
    for (int i = 0; i < m; ++i) {
        cin >> ar[i].u >> ar[i].v >> ar[i].w;
        ar[i].u--;
        ar[i].v--;
    }
    vector<ll> dist(n, INF);
    dist[s] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (const auto& t : ar) {
            if (dist[t.u] != INF && dist[t.u] + t.w < dist[t.v]) {
                dist[t.v] = dist[t.u] + t.w;
            }
        }
    }
    bool neg_cycle = false;
    for (const auto& t : ar) {
        if (dist[t.u] != INF && dist[t.u] + t.w < dist[t.v]) {
            neg_cycle = true;
            break;
        }
    }
    if (neg_cycle) {
        cout << "Negative cycle";
    } else {
        for (int i = 0; i < n; ++i) {
            if (dist[i] == INF) {
                cout << "inf";
            } else {
                cout << dist[i];
            }
            cout << (i == n - 1 ? "" : " ");
        }
    }
    return 0;
}