#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

int ans = 0;
void log(int x) {
    if (x == 0) return;
    ans ++;
    log(x / 2);
}
void solve() {
    int n; cin >> n;
    log(n); cout << ans-1;
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