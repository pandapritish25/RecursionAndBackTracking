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
int depth(string s) {
    int depth = 0;
    int max_depth = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            depth ++;
            max_depth = max(max_depth , depth);
        }
        else {
            depth --;
            max_depth = max(max_depth , depth);
        }
    }
    return max_depth;
}
string s;
void generateParenthesis(int level , int n , int open , int close , int k) {
    if (level == n && isValid(s) && depth(s) == k) {
        ans.push_back(s); return;
    }
    if (open < n / 2) {
        s.push_back('(');
        generateParenthesis(level + 1 , n , open + 1 , close , k);
        s.pop_back();
    }
    if (close < n / 2) {
        s.push_back(')');
        generateParenthesis(level + 1 , n , open , close + 1 , k);
        s.pop_back();
    }
}

void solve() {  
    int n , k; cin >> n >> k;
    generateParenthesis(0 , n , 0 , 0 , k);
    for (auto x : ans) cout << x << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}