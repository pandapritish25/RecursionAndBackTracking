#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

const int N = 10;
int queens[N];
vector<vector<int>> ans;

bool isValid(int row , int col) {
    for (int pro = 0; pro < row; pro ++) {
        if (abs(row - pro) == abs(col - queens[pro])) return false;
        if (queens[pro] == col) return false;
    }
    return true;
}
void rec(int level , int n) {
    if (level == n) {
        vector<int> x;
        for (int i = 0; i < n; i++) x.push_back(queens[i]); ans.push_back(x);
        return;
    }

    for (int ch = 0; ch < n; ch++) {
        if (isValid(level , ch)) {
            queens[level] = ch;
            rec(level + 1 , n);
            queens[level] = -1;
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    memset(queens, -1, sizeof(queens));
    ans.clear();
    rec(0 , n);
    vector<string> temp; string x;
    vector<vector<string>> final_ans;

    for (int i = 0; i < n; i ++) x += '.';
    for (int i = 0; i < n; i ++) temp.push_back(x);

    vector<string> ans1 = temp;

    for (int i = 0; i < ans.size(); i++) {
        vector<int> t = ans[i];
        for (int j = 0; j < t.size(); j++) {
            ans1[j][t[j]] = 'Q';
        }
        final_ans.push_back(ans1);
        ans1 = temp;
    }
    return final_ans;
}
void solve() {
    int n; cin >> n;
    vector<vector<string>> final_ans = solveNQueens(n);

    for (auto x : final_ans) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }
}
signed main() {                                                                    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}