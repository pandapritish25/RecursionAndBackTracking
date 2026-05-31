#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

void func(int n) {
    if (n == 0) return;
    cout << "I love Recursion\n";
    func(n - 1);
}
void solve() {
    int n; cin >> n;
    func(n);
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