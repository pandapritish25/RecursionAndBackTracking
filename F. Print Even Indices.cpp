#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

vector<int> arr;
void func(int n) {
    if (n % 2 == 0) {
        if (n <= 0) return;
        cout << arr[n - 2] << " ";
        func(n - 2);
    }
    else {
        if (n < 0) return;
        cout << arr[n - 1] << " ";
        func(n - 2);
    }
}
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
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