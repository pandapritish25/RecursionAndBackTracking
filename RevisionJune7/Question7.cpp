#include<bits/stdc++.h>
using namespace std;
#define int long long

void kthMoveTowerOfHanoi(int source , int dest , int aux , int k , int n) { 
    int ans1 = pow(2 , n - 1);
    if (k < ans1) kthMoveTowerOfHanoi(source , aux , dest , k , n - 1);
    else if (k == ans1) {
        cout << source << ' ' << dest << endl; return;
    }
    else kthMoveTowerOfHanoi(aux , dest , source , k - ans1 , n);
}
void solve() {  
    int n , k; cin >> n >> k;
    kthMoveTowerOfHanoi(1 , 3 , 2 , k , n);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}