#include<bits/stdc++.h>
using namespace std;
#define int long long


int rec(int n , int k , int root) {
    // one element
    if (n == 1) return root;

    int total_elements = pow(2 , n - 1); int mid_elements = total_elements / 2;

    if (mid_elements < k) {
        // go right
        int new_root = 0;
        if (root == 0) new_root = 1; else if (root == 1) new_root = 0;
        return rec(n - 1 , k - mid_elements , new_root);
    }
    else {
        // go left
        int new_root = 0;
        if (root == 0) new_root = 0; else if (root == 1) new_root = 1;
        return rec(n - 1 , k , new_root);
    }
}
int kthGrammar(int n, int k) {
    return rec(n , k , 0);
}
void solve() {
    int n , k; cin >> n >> k;
    cout << kthGrammar(n , k);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}