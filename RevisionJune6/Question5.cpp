#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 17;
int queens[N];
bool isValid(int row , int col) {
    // rememver queens can move anywhere where they would like but not the same case with horses , horses can only move 
    // one at a time for that reason we would consider only the horses outside not inside the value
    for (int prow = 0; prow < row; prow ++) {
        int pcol = queens[prow];
        if (pcol == col || abs(pcol - col) == abs(prow - row)) return false;
    }
    if (row - 1 >= 0 && (queens[row - 1] == col + 2 || queens[row - 1] == col - 2)) return false;
    if (row - 2 >= 0 && (queens[row - 2] == col + 1 || queens[row - 2] == col - 1)) return false;
    return true;
}
int rec(int level , int n) {
    if (level == n) return 1;
    int ans = 0;

    for (int ch = 0; ch < n; ch ++) {
        if (isValid(level , ch)) {
            queens[level] = ch; ans += rec(level + 1 , n); queens[level] = -1;
        }
    }
    return ans; 
}

void solve() {  
    memset(queens , -1 , sizeof(queens));
    int n; cin >> n;
    cout << rec(0 , n);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}