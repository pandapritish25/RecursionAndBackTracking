#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

void solve() {
    int n , m; cin >> n >> m;
    int count = 0;

    for (int i = 0; i <= 1001; i++) {
        for (int j = 0; j <= 1001; j++) {
            int ans1 = (i * i) + j; int ans2 = (j * j) + i;
            if (ans1 == n && ans2 == m) count ++;
        }
    }
    cout << count;
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