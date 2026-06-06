#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<string> ans;

bool isValid(string s) {
    stack<char> st;
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
string s;
void generateParenthesis(int level , int n , int open , int close) {
    if (level == n && isValid(s)) {
        ans.push_back(s);
        return;
    }
    if (open < n / 2) {
        s.push_back('('); generateParenthesis(level + 1 , n , open + 1 , close); s.pop_back();
    }
    if (close < n / 2) {
        s.push_back(')'); generateParenthesis(level + 1 , n , open , close + 1); s.pop_back();
    }
}

void solve() {  
    int n; cin >> n;
    generateParenthesis(0 , n , 0 , 0);
    for (auto x : ans) cout << x << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}