#include<bits/stdc++.h>
using namespace std;

const int size = 15;
int queens[15]; int n;

bool isvalid(int row , int col) {
    for (int pr = 0; pr < row; pr ++) {
        int pcol = queens[pr];
        if (abs(pcol - col) == abs(pr - row) || pcol == col) return false;
    }
    if (row - 1 >= 0) if (queens[row - 1] == col - 2 || queens[row - 1] == col + 2) return false;
    if (row - 2 >= 0) if (queens[row - 2] == col - 1 || queens[row - 2] == col + 1) return false;  
    return true;
}
int rec(int level) {
    if (level == n) return 1;
    int ans = 0;
    for (int ch = 0; ch < n; ch ++) {
        if (isvalid(level , ch)) {
            queens[level] = ch; ans += rec(level + 1); queens[level] = -1;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    memset(queens , -1 , sizeof(queens));
    
    cin >> n;
    cout << rec(0);
}