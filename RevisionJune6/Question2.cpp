#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 8;
char queens[N][N];
int queen[N];

bool isValid(int row , int col) {
    for (int prow = 0; prow < row; prow++) {
        int pcol = queen[prow];
        if (pcol == col || abs(pcol - col) == abs(prow - row)) return false;
    }
    return true;
}
int rec(int level , int n) {
    if (level == n) return 1;
    int ans = 0;
    // why you are always doing rec(level + 1 , ch) ideally see the recursion and then only put the params
    // thus the value should be rec(level + 1 , n);

    for (int ch = 0; ch < n; ch ++) {
        if (isValid(level , ch) && queens[level][ch] == '.') {
            queen[level] = ch; ans += rec(level + 1 , n); queen[level] = -1;
        }
    }
    return ans;
}
void solve() {  
    memset(queen , -1 , sizeof(queen));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)cin >> queens[i][j];
    }
    cout << rec(0 , 8);
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}