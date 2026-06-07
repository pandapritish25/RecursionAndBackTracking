#include<bits/stdc++.h>
using namespace std;
#define int long long

// shorter form question 5
int rec(int n , int k , int root) {
    if (n == 1) return root;
    
    if (pow(2 , n - 2) < k) return rec(n - 1 , k - pow(2 , n - 2) , (root == 0 ? 1 : 0));
    else return rec(n - 1 , k , root);
}
int kthGrammar(int n, int k) {
    return rec(n , k , 0);
}
void solve() {
    int n , k; cin >> n >> k; cout << kthGrammar(n , k);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}