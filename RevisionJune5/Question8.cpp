#include<bits/stdc++.h>
using namespace std;

bool isPalin(int start , int end, string &s) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start ++; end --;
    }
    return true;
}
vector<vector<string>> ans , final_ans;;
vector<string> x_helper;

void rec(string &s , int level) {
    if (level == s.length()) {
        ans.push_back(x_helper); return;
    }
    int n = s.length();

    for (int i = level; i < n; i++) {
        if (isPalin(level , i , s)) {
            x_helper.push_back(s.substr(level , i - level + 1));
            rec(s , i + 1);
            x_helper.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    rec(s , 0); final_ans = ans;
    ans.clear();
    return final_ans;
}
void solve() {
    string s; cin >> s;
    vector<vector<string>> ans = partition(s);

    for (auto x : ans) {
        for (auto i : x) cout << i << " ";
        cout << endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    solve();
}