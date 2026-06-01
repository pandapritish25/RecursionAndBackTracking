#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

vector<vector<int>> output;
vector<int> subset; vector<int> use = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9};

void rec(int level , int n , int k) {
    if (subset.size() == k) {
        if (n == 0) output.push_back(subset);
        return;
    }
    for (int i = level; i < 9; i++) {
        subset.push_back(use[i]);
        rec(i + 1 , n - use[i] , k);
        subset.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    rec(0 , n , k);
    return output;
}
void solve() {
    int n , k; cin >> n >> k;
    vector<vector<int>> ans = combinationSum3(k , n);
    for (auto x : ans) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }
}
signed main() {                                                                    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}