#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

double sum = 0;
vector<double> arr;
void func(int n) {
    if (n == 0) return;
    sum = sum + arr[n - 1];
    func(n - 1);
}   
void solve() {
    int n; cin >> n; 
    for (int i = 0; i < n; i++) {
        double a; cin >> a;
        arr.push_back(a);
    }
    func(n);
    double ans1 = sum , ans2 = n;
    cout << setprecision(6) << fixed << ans1 / (ans2 * 1.0) << endl;
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