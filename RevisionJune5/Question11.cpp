#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n , k; cin >> n >> k;
    int count = 0;

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            int ans1 = (i * i) + j; int ans2 = (j * j) + i;
            if (ans1 == n && ans2 == k) count ++;
        }
    }
    cout << count << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}