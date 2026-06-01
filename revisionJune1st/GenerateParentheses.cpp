#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()

vector<string> output;
string s;

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
void rec(int n , int level , int open , int close) {
    if (level == 2 * n && isValid(s)) {
        output.push_back(s);
        return;
    }
    if (open < n) {
        s.push_back('('); rec(n , level + 1 , open + 1 , close); s.pop_back();
    }
    if (close < n) {
        s.push_back(')'); rec(n , level + 1 , open , close + 1); s.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    rec(n , 0 , 0 , 0);
    return output;
}
void solve() {
    int n; cin >> n;
    vector<string> ans = generateParenthesis(n);

    for (auto x : output) cout << x << endl;
    
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