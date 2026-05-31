#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n; cin >> n;
    for (int i = -120; i <= 120; i++) {
        for (int j = -120; j <= 120; j++) {
            int ans1 = i * i * i * i * i; int ans2 = j * j * j * j * j;
            if (ans1 - ans2 == n) {
                cout << i << " " << j << endl; return;
            } 
        }
    }
}   

signed main() {                                                                    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    while (t--) {
        solve();
    }
    return 0;
}