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
vector<int> percompute;

int makeNums(vector<int> perm) {
    int ans = 0;
    for (int i = 0; i < perm.size(); i++) ans = (ans * 10) + perm[i];
    return ans;
}
void rec(int level , int n , vector<int> perm) {
    if (level == (n + 1) / 2) {
        for (int i = (n / 2) - 1; i >= 0; i--) perm.push_back(perm[i]);

        int num = makeNums(perm);
        if (isPrime(num)) percompute.push_back(num);
        return;
    }
    int start = 0;
    if (level == 0) start = 1;

    for (int i = start; i <= 9; i++) {
        perm.push_back(i); rec(level + 1 , n , perm); perm.pop_back();
    }
}

void solve() {
    int n , x; cin >> n >> x; vector<int> perm;
    
    for (int i = 1; i <= 9; i++) rec(0 , i , perm);
    int count = 0;
    for (int i = 0; i <= percompute.size(); i++) if (percompute[i] >= n && percompute[i] <= x) count ++;
    cout << count;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}   