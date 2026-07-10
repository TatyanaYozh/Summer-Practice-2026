//
// Created by YOJ on 10.07.2026.
//
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long out = 2;
    for (int i = 3; i < n; i++) {
        out = out * i % 1000000007;
    }
    out = out * 500000004 % 1000000007;
    cout << out;
}