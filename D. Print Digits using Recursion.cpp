#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

void func(int n) {
    if (n == 0) return;
    func(n / 10);
    cout << n % 10 << " ";
}
void solve() {
    int n; cin >> n;
    if (n == 0) {
        cout << 0 << endl; return;
    }   
    func(n);
    cout << "\n";
}   

signed main() {                                                                    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}