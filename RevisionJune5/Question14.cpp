#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << 1 << " " << 0 << endl;
        return;
    }
    for (int i = -200; i < 200; i++) {
        for (int j = -200; j < 200; j++) {
            int ans1 = i * i * i * i * i; int ans2 = j * j * j * j * j;
            if (ans1 - ans2 == n) {
                cout << i << " " << j << endl; return;
            }
        }
    }
    cout << -1 << " " << -1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}