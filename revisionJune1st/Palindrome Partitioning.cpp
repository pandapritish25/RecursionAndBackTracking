#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

vector<vector<string>> ans;
vector<string> helper;

bool palindrome(string s, int start , int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start ++; end --;
    }
    return true;
}

void rec(int n , string s , int level) {
    if (level == n) {
        ans.push_back(helper); return;
    }
    for (int i = level; i < n; i++) {
        if (palindrome(s , level , i)) {
            helper.push_back(s.substr(level , i - level + 1));
            rec(n , s , i + 1);
            helper.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    rec(s.length() , s , 0);
    return ans;
}

void solve() {
    string s; cin >> s;
    vector<vector<string>> ans = partition(s);

    for (auto x : ans) {
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