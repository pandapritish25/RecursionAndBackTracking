#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

int ans = 0;
void seq(int n) {
    if (n == 1) return;
    ans ++;
    if (n % 2 == 0) seq(n / 2);
    else if (n % 2 == 1) seq(3 * n + 1);
}   
void solve() {
    int n; cin >> n; seq(n);
    cout << ans + 1;
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