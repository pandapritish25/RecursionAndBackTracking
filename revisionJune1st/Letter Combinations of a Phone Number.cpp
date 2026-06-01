#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

vector<string> mapping = {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};

vector<string> ans;

void rec(int start , string s , string &digits) {
    if (s.length() == digits.length()) {
        ans.push_back(s); return;
    }
    string ans2 = mapping[digits[start] - '0'];
    
    for (int j = 0; j < ans2.length(); j++) {
        s.push_back(ans2[j]);
        rec(start + 1 , s , digits);
        s.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    string s; rec(0 , s , digits);
    return ans;
}
void solve() {
    string s; cin >> s;
    vector<string> ans = letterCombinations(s);
    for (auto x : ans) cout << x << " ";
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