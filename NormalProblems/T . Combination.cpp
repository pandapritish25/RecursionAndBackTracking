#include <bits/stdc++.h>
using namespace std;
#define int long long

int ncr(int n, int r) {
    if (r == 0)
        return 1;

    return (n * ncr(n - 1, r - 1)) / r;
}

void solve() {
    int n, r;
    cin >> n >> r;

    if (r > n) {
        cout << 0 << endl;
        return;
    }

    cout << ncr(n, r) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}