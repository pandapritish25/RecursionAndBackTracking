#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    std::stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') st.push(s[i]);
        else if (s[i] == ')') {
            if (!st.empty() && st.top() == '(') st.pop();
            else return false;
        }
    }
    if (!st.empty()) return false;
    return true;
}
vector <string> ans , final_ans;
void rec(int n , string s , int level , int open , int close) {
    if (level == 2 * n && isValid(s)) {
        ans.push_back(s); return;
    }
    if (open < n) {
        s.push_back('('); rec(n , s , level + 1 , open + 1 , close); s.pop_back();
    }
    if (close < n) {
        s.push_back(')'); rec(n , s , level + 1 ,open , close + 1); s.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    string s; rec(n , s , 0 , 0 , 0);
    final_ans = ans; ans.clear();
    return final_ans;
}
void solve() {
    int n; cin >> n;
    vector<string> v = generateParenthesis(n);
    for (auto x : v) cout << x << endl;
}
signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}