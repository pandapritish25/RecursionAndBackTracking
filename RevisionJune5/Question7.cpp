#include<bits/stdc++.h>
using namespace std;

vector<string> mapping = {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};

vector<string> final_ans , x_helper;
void rec(int level , string digits , string ans) {
    if (ans.length() == digits.length()) {
        final_ans.push_back(ans); return;
    }
    int digit = digits[level] - '0'; string ans2 = mapping[digit];
    for (int i = 0; i < ans2.length(); i++) {
        ans.push_back(ans2[i]); rec(level + 1 , digits , ans);
        ans.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    string ans; rec(0 , digits , ans);
    x_helper = final_ans; final_ans.clear();
    return x_helper;
}
void solve() {
    string digits;
    cin >> digits;
    vector<string> y = letterCombinations(digits);
    for (auto x : y) cout << x << " ";
}
signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}