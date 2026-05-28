#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

int ans = 1;
void func(int n) {
    if (n == 0) return;
    ans = ans * n;
    func(n - 1);
}
void solve() {
    int n; cin >> n;
    func(n);
    cout << ans;
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