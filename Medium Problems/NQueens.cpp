#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

const int N = 10;
vector<int> queens(N , -1);
vector<int> queens1(N , -1);
vector<vector<int>> output;

bool isValid(int row , int col) {
    for (int pr = 0; pr < row; pr ++) {
        int prev_col = queens[pr]; 
        if (prev_col == col || abs(row - pr) == abs(col - prev_col)) return false;
    }
    return true;
}
int rec(int level , int n) {
    if (level == n) {
        output.push_back(queens);
        return 1; 
    }
    int ans = 0;
    for (int ch = 0; ch < n; ch ++) {
        if (isValid(level , ch)) {
            queens[level] = ch;
            ans = ans + rec(level + 1 , n);
            queens[level] = -1;
        }
    }
    return ans;
}
vector<vector<string>> solveNQueens(int n) {
    rec(0 , n);
    vector<string> make; char dot = '.'; 
    string make1;
    for (int i = 0; i < n; i++) make1.push_back(dot);
    for (int i = 0; i < n; i++) make.push_back(make1);
    vector<string> temp = make;
    
    int count = 0; vector<vector<string>> ans;

    for (int i = 0; i < output.size(); i++) {
        vector<int> ans1 = output[i];
        for (int j = 0; j < n; j++) {
            make[j][ans1[j]] = 'Q';
        }
        ans.push_back(make);
        make = temp;
    }
    return ans;
}
void solve() {
    int n; cin >> n;    
    vector<vector<string>> x_helper = solveNQueens(n);
    for (auto t : x_helper) {
        for (auto y : t) cout << y << " ";
        cout << endl;
    }
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