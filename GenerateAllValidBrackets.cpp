#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

vector<char> gener ; 
vector<char> v;
int n;
string s;

bool valid_parenthesis(string s) {
    stack<int> st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') st.push('(');
        else if (s[i] == ')') {
            if (!st.empty() && st.top() == '(') st.pop();
            else return false;
        }
    }
    if (!st.empty()) return false;
    return true;
}

void Parenthesis(int level , int open , int close) {
    if (level == 2 * n) {
        if (valid_parenthesis(s)) {
            cout << s << endl;
        }
        return;
    }
    if (open < n) {
        s.push_back('(');
        Parenthesis(level + 1 , open + 1 , close);
        s.pop_back();
    }
    if (close < n) {
        s.push_back(')');
        Parenthesis(level + 1 , open , close + 1);
        s.pop_back();
    }
}

void solve() {
    cin >> n;
    Parenthesis(0 , 0 , 0);
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