#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

vector<int> perm ; 
vector<int> v;

bool check(vector<bool> &used , int n) {
    if (used[n] == 0) return true;
    return false;
} 
void generatePermutations(int level , vector<bool> &used) {
    if (level == v.size()) {
        for (auto x : perm) cout << x << " ";
        cout << endl; return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (check(used , i)) {
            perm.push_back(v[i]);
            used[i] = true;
            generatePermutations(level + 1 , used);
            perm.pop_back();
            used[i] = false;
        }
    }

}
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        v.push_back(a);
    }
    vector<bool> used(n , false);
    generatePermutations(0 , used);
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