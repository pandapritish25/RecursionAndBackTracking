#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

vector<string> v;
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

bool depth(string s , int k) {
    int depth = 0 , max1 = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') depth ++ , max1 = max(max1 , depth);
        else if (s[i] == ')') depth -- , max1 = max(max1 , depth);
    }
    return max1 == k;
}

void rec(int level , int open , int close , int n , int k) {
    if (level == 2 * n) {
        if (isValid(s) && depth(s , k)) v.push_back(s);
        return;
    }
    if (open < n) {
        s.push_back('(');
        rec(level + 1 , open + 1 , close , n , k);
        s.pop_back();
    }
    if (close < n) {
        s.push_back(')');
        rec(level + 1 , open , close + 1 , n , k);
        s.pop_back();
    }
}
void solve() {
    int n , k; cin >> n >> k; n >>= 1;
    rec(0 , 0 , 0 , n , k);
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