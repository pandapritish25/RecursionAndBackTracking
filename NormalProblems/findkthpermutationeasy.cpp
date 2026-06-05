#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

int fact[100005];
const int MOD = 1e9 + 7;

vector<int> ans;
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < 100005; i++) {
        fact[i] = min(MOD , fact[i - 1] * i);
    }
}

void findkth(int k , int n , vector<int> &v) {
    if (n == 0) return;
    int idx = (k - 1) / fact[n - 1];
    ans.push_back(v[idx]);
    v.erase(v.begin() + idx);
    // most tricky part
    k = (k - 1) % fact[n - 1] + 1;
    findkth(k , n - 1 , v);
}
void solve() {
    int n , k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = i + 1;
    findkth(k , n , v);
    for (auto x : ans) cout << x << " ";
}
signed main() {                                                                    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; // cin >> t;
    precompute();
    while (t--) {
        solve();
    }
    return 0;
}