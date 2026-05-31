#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

int ans = 0;
vector<int> arr;
int count1 = 0;
void func(int n , int m) {
    if (m == -1) return;
    ans += arr[n - 1];
    func(n - 1 , m - 1);
}
void solve() {
    int n,m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
    func(n , m - 1);
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