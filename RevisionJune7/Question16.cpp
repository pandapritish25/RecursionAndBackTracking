#include<bits/stdc++.h>
using namespace std;
#define int long long

bool isPrime(int n) {
    if (n <= 1)return false;
    if (n == 2 || n == 3)return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false;
    return true;
}
// key idea is simple , you can fix the 1st element so that in any kind of rotation , we would have that ans
// because any rotation would have 1st element as 1 only so its better
int ans = 0; const int N = 20;
int used[N];
vector<int> perm;

// so make sure to generate only permutations starting from 1 because rest all are just cycles
void rec(int level , vector<int> &v) {
    if (level == v.size() - 1) {
        if (isPrime(perm[0] + perm.back())) ans ++;
        // for (auto x : perm) cout << x << " "; cout << endl;
        return; 
    }

    for (int i = 0; i < v.size(); i++) {
        if (used[i] == 1) continue;
        if (!isPrime(perm.back() + v[i])) continue;
        if (used[i] == 0) {
            used[i] = 1; perm.push_back(v[i]);
            rec(level + 1 , v);
            used[i] = 0; perm.pop_back();
        }
    }
}
void solve() {
    memset(used , 0 , sizeof(used));
    int n; cin >> n; vector<int> v(n); for(int i = 0; i < n; i++) v[i] = (i + 1);
    if (n & 1) {
        cout << 0; return;
    }
    used[0] = 1; perm.push_back(1);
    rec(0 , v); cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}