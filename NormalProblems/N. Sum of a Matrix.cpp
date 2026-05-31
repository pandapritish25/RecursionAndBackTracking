#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

void func(vector<vector<int>> &a , vector<vector<int>> & b,int n,int m , int i , int j) {
    if (i == n) return;
    if (j == m) {
        func(a , b , n , m , i + 1 , 0);
        return;
    }
    cout << a[i][j] + b[i][j] << " ";
    if (j == m - 1) cout << "\n";
    func(a , b , n , m , i , j + 1);
}
void solve() {
    int n , m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    func(a , b , n , m , 0 , 0);
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