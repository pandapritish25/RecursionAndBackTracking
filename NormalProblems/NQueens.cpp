#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

int n;
int queens[100];

bool check(int row , int col) {
    // check if we can place the queens without getting attacked
    for (int pr = 0; pr < row; pr ++) {
        int pc = queens[pr];
        // (old queens is present in pr , pc) inside the folder
        // (pr , pc has a queen and check if you can attach this row,col)
        if (pc == col || abs(row - pr) == abs(col - pc)) return 0;
    }
    return 1;
}
int rec(int level) {
    // explore all the possible solutions after exploring the previous ones 
    // like you have explored all the previous levels and now you need to go and explore the next ones
    // and then exactly count the no of ways in which the solutions are valid like you need to count exactly which solutions are valid
    // like you are inside one level , you need to calculate which all of the levels are valid in the scenario

    // base case and 
    if (level == n) {
        return 1;
    }

    int ans = 0;
    //recusive case

    // go through all the coloumns and then check can I place my queen here or not
    for (int ch = 0; ch < n; ch++) {
        if (check(level , ch)) {
            // move // place
            queens[level] = ch;
            // go into recursion
            ans += rec(level + 1);
            // unplace
            queens[level] = -1;
        }
    }

    return ans;
}
void solve() {
    cin >> n;
    // state is like a data structure for you and you need to maintain the set for that data structure
    memset(queens , -1 , sizeof(queens));
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