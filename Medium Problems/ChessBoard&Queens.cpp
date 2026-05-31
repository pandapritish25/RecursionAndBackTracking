#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

const int N = 8;
int queens[N];
char matrix[N][N];

bool isValid(int row , int col) {
    for (int pr = 0; pr < row; pr ++) {
        int ccol = queens[pr];
        if (col == ccol || (abs(pr - row)) == abs(col - ccol)) return false;
    }
    return true;
}
int rec(int level) {
    if (level == N) return 1;
    
    int ans = 0;

    for (int ch = 0; ch < N; ch++) {
        if (isValid(level , ch) && matrix[level][ch] == '.') {
            queens[level] = ch;
            ans += rec(level + 1);
            queens[level] = -1;
        }
    }
    return ans;
}
void solve() {
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> matrix[i][j];
    cout << rec(0);
    
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