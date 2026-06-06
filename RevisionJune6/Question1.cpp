#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 10;
int queens[N];
vector<vector<int>> v;

bool isValid(int row , int col) {
    for (int prow = 0; prow < row; prow++) {
        int pcol = queens[prow];
        if (pcol == col || abs(prow - row) == abs(pcol - col)) return false;
    }
    return true;
}

int rec(int level , int n) {
    if (level == n) {
        vector<int> ans1;
        for (int i = 0; i < n; i++) ans1.push_back(queens[i]);
        v.push_back(ans1);
        return 1;
    }
    int ans = 0;
    // here inside n queens what exactly is you are comparing the coloumns with the level and thus for this 
    // reason what needs to be done is that you need to check from 0 that if this is possible to have any coloumn or not

    for (int ch = 0; ch < n; ch ++) {
        if (isValid(level , ch)) {
            queens[level] = ch;
            ans += rec(level + 1 , n); 
            queens[level] = -1; 
        }
    }
    return ans;
}

vector<vector<string>> solveNQueens(int n) {
    memset(queens , -1 , sizeof(queens));
    rec(0 , n);
    vector<vector<string>> helper;
    string x = "";
    for (int i = 0; i < n; i++) x += '.';
    vector<string> temp , ans1;
    for (int i = 0; i < n; i++) temp.push_back(x);
    ans1 = temp;

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            ans1[j][v[i][j]] = 'Q';
        }
        helper.push_back(ans1);
        ans1 = temp;
    }
    return helper;
}
void solve() {  
    int n; cin >> n;
    vector<vector<string>> helper = solveNQueens(n);
    for (auto x : helper) {
        for (auto y : x) cout << y << " ";
        cout << endl; 
    }
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}