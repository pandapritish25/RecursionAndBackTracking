#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

vector<int> arr;
bool ispalin(int l , int r) {
    if (r - l + 1 <= 1) return true;
    if (arr[l] != arr[r]) return false;
    return ispalin(l + 1 , r - 1);
}   
void solve() {
    int n; cin >> n; 
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
    bool ans = ispalin(0 , n - 1);
    cout << (ans ? "YES\n" : "NO\n");
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