#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

int ans = 0;
vector<int> arr;
void func(int n) {
    if (n == 0) return;
    ans += arr[n - 1];
    func(n - 1);
}
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
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