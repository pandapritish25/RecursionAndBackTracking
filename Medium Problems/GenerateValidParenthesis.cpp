#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

vector<string> output;
string s;

bool valid_parenthesis(string s) {
    stack <int> st;
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

void rec(int level , int open , int close , int n) {
    if (level == 2 * n && valid_parenthesis(s)) {
        output.push_back(s); return;
    }
    if (open < n) {
        s.push_back('('); rec(level + 1 , open + 1 , close , n); s.pop_back();
    }
    if (close < n) {
        s.push_back(')'); rec(level + 1 , open , close + 1 , n); s.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    rec(0 , 0 , 0 , n);
    return output;
}
void solve() {
    int n; cin >> n;
    vector<string> v = generateParenthesis(n);
    for (auto x : v) cout << x << "\n";
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