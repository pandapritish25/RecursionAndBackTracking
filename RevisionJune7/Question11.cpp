// well form for question 10
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 55;
int level[N]; int pati[N];

int ans = 0;

int rec(int n , int k) {
    if (k == 0) return 0;
    if (n == 0) {
        ans ++; return 1;
    }
    if (k <= (1 + level[n - 1])) {
        rec(n - 1 , k - 1); return 1;
    }
    if (k == (2 + level[n - 1])) {
        ans += (pati[n - 1] + 1); return 1;
    }
    if (k > 2 + level[n - 1]) {
        ans += (pati[n - 1] + 1); rec(n - 1 , k + 2 - level[n - 2]);
        return 1;
    }
    return 0;
}
void solve() {  
    int n , x; cin >> n >> x;
    level[0] = 1; pati[0] = 1;

    for (int i = 1; i < 55; i++) {
        level[i] = 2 * level[i - 1] + 3;
        pati[i]  = 2 * pati[i - 1] + 1;
    }
    ans = 0;
    int total = level[n] - x;
    rec(n , total);  cout << pati[n] - ans;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}