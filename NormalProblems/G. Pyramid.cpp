#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

void print_space(int n) {
    if (n == 0) return;
    cout << " ";
    print_space(n - 1);
}
void print_star(int n) {
    if (n == 0) return;
    cout << "*";
    print_star(n - 1);
}
void pyramid(int row , int n) {
    if (row > n) return;
    print_space(n - row);
    print_star(2 * row - 1);
    cout << "\n";

    pyramid(row + 1 , n);
}
void solve() {
    int n; cin >> n;
    pyramid(1 , n);
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