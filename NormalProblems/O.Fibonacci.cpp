#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

int fib(int x) {
    if (x == 1) return 0;
    if (x == 2) return 1;
    return fib(x-1) + fib(x-2); 
}
void solve() {
    int n; cin >> n;
    cout << fib(n);
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