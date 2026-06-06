#include<bits/stdc++.h>
using namespace std;
#define int long long

void tower_of_hanoi(int source , int destination , int auxilary , int n) {
    if (n == 0) return;
    tower_of_hanoi(source , auxilary , destination , n - 1);
    cout << source << " " << destination << "\n";
    tower_of_hanoi(auxilary , destination , source , n - 1);
}
void solve() {  
    int n; cin >> n; 
    cout << pow(2 , n) - 1 << "\n"; 
    tower_of_hanoi(1 , 3 , 2 , n);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}