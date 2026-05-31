#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

void tower_of_hanoi(int n , int source , int destination , int auxilary) {
    if (n == 0) return;
    tower_of_hanoi(n - 1 , source , auxilary , destination);
    cout << source << " " << destination << endl;
    tower_of_hanoi(n - 1 , auxilary , destination , source);
}
void solve() {
    int n; cin >> n;
    cout << pow(2 , n) - 1 << "\n";
    tower_of_hanoi(n , 1 , 3 , 2);
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